#define ca1 30
#define ca2 31
#define ca3 32
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
    for(byte i = 2 ; i <10 ; i++ )
    {
        pinMode(i, OUTPUT);
    }
    digitalWrite(9, HIGH);
    pinMode(ca1, OUTPUT);
    pinMode(ca2, OUTPUT);
    pinMode(ca3, OUTPUT);
    pinMode(A13, OUTPUT);
    digitalWrite(A13, LOW);    
}
void loop()
{
     for(unsigned int number = 0 ; number <10000; number++)
    {
        unsigned long starttime = millis();
        for(unsigned long elapsed = 0 ; elapsed<1 ; elapsed=millis()-starttime)
        {
            pickdigit(1);
            lightdigit(number%10,1);
            delay( delaytime );
            pickdigit(2);
            lightdigit((number/10)%10,2);
            delay( delaytime );
            pickdigit(3,);
            lightdigit((number/100)%10,3);
            delay( delaytime );
            pickdigit(4);
            lightdigit((number/1000)%10,4);
            delay( delaytime );

        
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