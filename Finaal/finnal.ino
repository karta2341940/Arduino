/*
*摩斯密碼規則:
*點為一個時間長度
*劃為三個時間長度
*單字間
*
*
*
*
*/

String morseCode[4][4]={
    "0010","0","100","1010",
    "1000","00011","10000","11110",
    "01","00111","00000","11100",
    "11111","01111","00001","11000"};
String morseTemp[2];
#define output OUTPUT
#define high HIGH
#define input INPUT
#define low LOW
int buzzer = A9;
#include <LiquidCrystal.h>
#include <Keypad.h>
const byte row = 4;
const byte col = 4;
char hexaKeys[row][col]={
    'F','E','D','C',
    'B','3','6','9',
    'A','2','5','8',
    '0','1','4','7',};
byte rowp[row]={25,24,23,22};
byte colp[col]={29,28,27,26};
LiquidCrystal lcd(49,48,47,43,42,41);

Keypad pad =Keypad(makeKeymap(hexaKeys),rowp,colp,row,col);


void setup()
{

    pinMode(buzzer, output);
    lcd.begin(16,2);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Type in time");
    lcd.setCursor(0,1);
    lcd.print("____ Second");
    Serial.begin(9600);
    
}
int cursorIndex=0;
String inpu="";
int taimu=0;
int sw = 1;
String ans = "" ;
String Pswd="FE";
int timer = 50;
int r,c;
void loop()
{

    lcd.setCursor(cursorIndex,1);
    char ckey = pad.getKey();
    if( ckey ){
        
        if(sw){
            
            lcd.print(ckey);
            inpu+=ckey;
            cursorIndex+=1;

            if(cursorIndex==4)
            {

                cursorIndex=0;
                lcd.setCursor(cursorIndex,1);
                delay(1000);
                lcd.print("____");
                lcd.setCursor(cursorIndex,1);
                taimu=inpu.toInt();
                //Serial.println(inpu.toInt());
                inpu="";
                sw=0;
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("Input Passwd");
                lcd.setCursor(0,1);
                Pswd="";
                generalPwd();
                for(int i = 0 ; i < 2 ; i++)
                {
                    morse(morseTemp[i]);
                    delay(1000);
                }

            }

        }

        else if(!sw) {
            
            ans+=ckey;
            lcd.print(ckey);
            cursorIndex+=1;
            
            
            


            if(cursorIndex==2)
            {
                cursorIndex=0;
                lcd.setCursor(cursorIndex,1);
                delay(1000);
                lcd.print("      ");
                lcd.setCursor(cursorIndex,1);

                if( ans == Pswd)
                {
                    sw=1;
                    ans="";
                    lcd.clear();
                    lcd.setCursor(0,0);
                    lcd.print("Type in time");
                    lcd.setCursor(0,1);
                    lcd.print("____ Second");
                }
                else 
                {
                    lcd.clear();
                    lcd.setCursor(0,0);
                    lcd.print("Input Passwd");
                    lcd.setCursor(0,1);
                    ans="";
                }
            }
        }

    }

  
        
        
    
    
}

void generalPwd(){
    r = random(0, 4);
    c = random(0, 4);
    Pswd+=hexaKeys[r][c];
    morseTemp[0]=morseCode[r][c];
    delay(100);
    r = random(0, 4);
    c = random(0, 4);
    Pswd+=hexaKeys[r][c];
    morseTemp[1]=morseCode[r][c];
    Serial.println(Pswd);
}

void morse( String inStr )
{
    for( int i = 0 ; i <inStr.length(); i++ )
    {
        char outpu = inStr[i];
        if( outpu == '0')
        {
            digitalWrite(A9, high);
            delay(80);
            digitalWrite(A9, low);
            delay(100);
        }
        else {
            digitalWrite(A9, high);
            delay(240);
            digitalWrite(A9, low);
            delay(100);
        }
    }
}


