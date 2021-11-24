int red = 44;
int gre = 45;
//----------------
#include <Keypad.h>
const byte rows = 4;
const byte cols = 4;
char hexakeys[rows][cols]={
    {'F','E','D','C'},
    {'B','3','6','9'},
    {'A','2','5','8'},
    {'0','1','4','7'}};
    
byte rowpin[rows]={25,24,23,22};
byte colpin[cols]={29,28,27,26};

Keypad keypad = Keypad( makeKeymap(hexakeys), rowpin , colpin , rows , cols );



//------------------------------------------------
#define ca1 30
#define ca2 31
#define ca3 32
#define high HIGH
#define low LOW



byte segs[7]={2,3,4,5,6,7,8};
byte ssd[11][7]=
{
  {0,0,0,0,0,0,1},//0
  {1,0,0,1,1,1,1},//1
  {0,0,1,0,0,1,0},//2
  {0,0,0,0,1,1,0},//3
  {1,0,0,1,1,0,0},//4
  {0,1,0,0,1,0,0},//5
  {0,1,0,0,0,0,0},//6
  {0,0,0,1,1,1,1},//7
  {0,0,0,0,0,0,0},//8
  {0,0,0,1,1,0,0},//9
  {1,1,1,1,1,1,1}
  
};

int delaytime =4;
void setup()
{
    for(byte i = 2 ; i <10 ; i++ )
    {
        pinMode(i, OUTPUT);
    }
    digitalWrite(9, 1);
    pinMode(red, OUTPUT);
    pinMode(gre, OUTPUT);
    pinMode(ca1, OUTPUT);
    pinMode(ca2, OUTPUT);
    pinMode(ca3, OUTPUT);
    pinMode(A13, OUTPUT);
    digitalWrite(A13, 0);
    analogWrite(gre,255);
    analogWrite(red,255);    
    Serial.begin(9600);
}
int is = 0;
char kk[4]={'0','0','0','0'};
void loop()
{

    char ckey = keypad.getKey();
        
        
        if(ckey && ckey != 'c')
        {
            kk[is] = ckey;       
            is++ ;
            if(is>3)is=0;
            digitalWrite(A13, 0);
        }
        if(ckey=='C')
        {
            digitalWrite(A13, 1);
            analogWrite(red,0);
            analogWrite(gre,255);
            for(int i = 0 ; i < 4 ; i ++ )
            {
                kk[i]='0';
            }
            is=0;
        }
        if(ckey != 'c')
        {

            
            lightdigit(String(kk[3]).toInt(),1);
            delay( delaytime );
            
            lightdigit(String(kk[2]).toInt(),2);
            delay( delaytime );
            
            lightdigit(String(kk[1]).toInt(),3);
            delay( delaytime );
            
            lightdigit(String(kk[0]).toInt(),4);
            delay( delaytime );
        }
        if(is == 3 )
        {
            if(kk[0]=='1')
                if(kk[1]=='4')
                    if(kk[2]=='5')
                        if(kk[3]=='0')
                        {
                            analogWrite(gre,0);
                            analogWrite(red,255);
                        }

        }
    
        //Serial.println(ckey);
    
        //for(unsigned int number = 0 ; number <10000; number++)
        //{
        //    unsigned long starttime = millis();
        //    for(unsigned long elapsed = 0 ; elapsed<100 ; elapsed=millis()-starttime)
        //    {
        //        pickdigit(1);
        //        lightdigit(String(kk[0]).toInt(),1);
        //        delay( delaytime );
        //        pickdigit(2);
        //        lightdigit(String(kk[1]).toInt(),2);
        //        delay( delaytime );
        //        pickdigit(3);
        //        lightdigit(String(kk[2]).toInt(),3);
        //        delay( delaytime );
        //        pickdigit(4);
        //        lightdigit(String(kk[3]).toInt(),4);
        //        delay( delaytime );
        //    }
        //}
    


 
}

void pickdigit(int x)
{

    digitalWrite(ca1, high);
    digitalWrite(ca2, high);
    digitalWrite(ca3, high);
    switch (x)
    {
    case 1:
        digitalWrite(ca1, LOW);
        digitalWrite(ca2, LOW);
        digitalWrite(ca3, LOW);
        break;
    case 2:
        digitalWrite(ca1, HIGH);
        digitalWrite(ca2, LOW);
        digitalWrite(ca3, LOW);
        break;
    case 3:
        digitalWrite(ca1, LOW);
        digitalWrite(ca2, HIGH);
        digitalWrite(ca3, LOW);
        break;
    case 4:
        digitalWrite(ca1, HIGH);
        digitalWrite(ca2, HIGH);
        digitalWrite(ca3, LOW);
        break;
    }
}

void lightdigit(byte number,byte x)
{
    pickdigit(x);
    lightSeg(number);
}
void lightSeg(byte number)
{
    for(int i = 0 ; i < 7 ; i ++)
    {
        digitalWrite(segs[i], ssd[number][i]);
    }
}