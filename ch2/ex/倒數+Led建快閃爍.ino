#define ca1 30
#define ca2 31
#define ca3 32
#define high HIGH
#define low LOW
#define output  OUTPUT
#define input   INPUT

//Led pin
int base =2;
int num = 8;
int ledpin =A15; //LED共陽
//ledPin end

byte segs[7]={2,3,4,5,6,7,8};
byte ssd[10][7]=
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
  {0,0,0,1,1,0,0}//9
};

int delaytime =4;
void setup()

{
    for(int i = base ; i <base+num; i++ )
    {
        pinMode(i, OUTPUT);
    }
        pinMode(ledpin, output);
    digitalWrite(ledpin,1);
    digitalWrite(9, 0);
    pinMode(ca1, OUTPUT);
    pinMode(ca2, OUTPUT);
    pinMode(ca3, OUTPUT);
    pinMode(A13, OUTPUT);
    digitalWrite(A13, LOW);    
}
void loop()
{
    
     for(int number = 20 ; number >=11; number--)
    {
        unsigned long starttime = millis();
        for(unsigned long elapsed = 0 ; elapsed<500 ; elapsed=millis()-starttime)
        {
            
            pickdigit(1);
            lightdigit(number%10,1);
            delay( delaytime );
            pickdigit(2);
            lightdigit((number/10)%10,2);
            delay( delaytime );
            
            
        
        }
    }

    for(int number = 10; number >=0; number--)
    {
        unsigned long starttime = millis();
        for(unsigned long elapsed = 0 ; elapsed<500 ; elapsed=millis()-starttime)
        {
            
            pickdigit(1);
            lightdigit(number%10,1);
            delay( delaytime );
            pickdigit(2);
            lightdigit((number/10)%10,2);
            delay( delaytime );
            digitalWrite(9,1);
            digitalWrite(A13,HIGH);
            digitalWrite(A15, LOW);
            for (int i = base; i < base + num; i ++) {
                digitalWrite(i, LOW);
            }
        
            delay(number*10);
            for (int i = base; i < base + num; i ++) {
                digitalWrite(i, HIGH);
            }
            digitalWrite(A15, HIGH);
            digitalWrite(A13,LOW);
        
        }
    }
     
     
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
