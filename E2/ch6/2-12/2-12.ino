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
    lcd.begin(16,2);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("TSMC = ?");
    lcd.setCursor(0,1);
    lcd.print(":");
}
int x=1;
char inpu[4] = {0};
char ans[4]={'2','3','3','0'};
void loop()
{
    lcd.setCursor(x,1);
    char ckey = pad.getKey();
    if( ckey )
    {
        lcd.print(ckey);
        inpu[x-1]=ckey;
        x+=1;

    }
    if(x==5)
    {
        x=1;
        lcd.setCursor(1,1);
        int la = 0;
        for(int i = 0 ; i < 4 ; i ++ )
        {
            if(inpu[i] == ans[i])
            {
                la+=1;
            }
            if(la==4)
            {
                delay(1000);
                lcd.print("        ");
                lcd.setCursor(1,1);
                lcd.print("O");
            }
            else 
            {
                delay(1000);
                lcd.print("        ");
                lcd.setCursor(1,1);
                lcd.print("X");
            }
        }
        delay(1000);
        lcd.setCursor(x,1);
        lcd.print("        ");
        for(int i = 0 ; i < 4 ; i ++ )
        {
            inpu[i]=' ';
        }
        
    }


}
