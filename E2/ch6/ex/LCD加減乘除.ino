#include <LiquidCrystal.h>
#include <Keypad.h>
const byte row = 4;
const byte col = 4;
char hexaKeys[row][col]={
    '+','-','*','//',
    '=','3','6','9',
    'C','2','5','8',
    '0','1','4','7',};
byte rowp[row]={25,24,23,22};
byte colp[col]={29,28,27,26};
LiquidCrystal lcd(49,48,47,43,42,41);

Keypad pad =Keypad(makeKeymap(hexaKeys),rowp,colp,row,col);

char asmd[6]={'+','-','*','//','C','='};

void setup()
{
    lcd.begin(16,2);
    lcd.clear();
    
}
int cursor = 0;
int x2=0;
int inp=0;
char ins[2]={0};
void loop()
{

    if(x < 3 )
    {

        lcd.setCursor(cursor,1);
        char ckey = pad.getKey();

        if( ckey )
        {
            lcd.print(ckey);
            ins[inp]=ckey;
            for(int i = 0 ; i < 5 ; i ++)
            {
                if( ckey == asmd[i])
                {
                    inp+=1;
                    x2 = i;
                }
            }
            
            cursor+=1;
            
        }
    }
    
    
}
