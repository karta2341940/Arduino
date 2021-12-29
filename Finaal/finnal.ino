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
void loop()
{
    lcd.setCursor(cursorIndex,1);
    char ckey = pad.getKey();
    if( ckey )
    {
        if(sw){
            
            lcd.print(ckey);
            inpu+=ckey;
            cursorIndex+=1;
        }
        else {

            lcd.print(ckey);
            ans+=ckey;
            cursorIndex+=1;
        }

    }
    if(sw)
    {
        if(cursorIndex==4)
        {
            cursorIndex=0;
            lcd.setCursor(cursorIndex,1);
            delay(1000);
            lcd.setCursor(cursorIndex,1);
            lcd.print("    ");
            taimu=inpu.toInt();
            Serial.print(inpu.toInt()+1);
            inpu="";
            sw=0;
        }
    }
    else
    {

    }


    
}



