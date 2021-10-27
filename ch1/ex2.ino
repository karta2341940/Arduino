#define ca1 30
#define ca2 31
#define ca3 32
#define low LOW
#define high HIGH



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
            picknumber(number%10);
            delay( delaytime );
            pickdigit(2);
            picknumber((number/10)%10);
            delay( delaytime );
            pickdigit(3);
            picknumber((number/100)%10);
            delay( delaytime );
            pickdigit(4);
            picknumber((number/1000)%10);
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
void picknumber(int x )
{
    switch (x)
    {
    case 1:
        one();
        break;
    case 2:
        two();
        break;
    case 3:
        three();
        break;
    case 4:
        four();
        break;
    case 5:
        five();
        break;                
    case 6:
        six();
        break;
    case 7:
        seven();
        break;
    case 8:
        eight();
        break;
    case 9:
        nine();
        break;
    default:
        zero();
        break;
                            
    }
}
void one()
{
    byte hl[7]={1,0,0,1,1,1,1};
    for(int i = 2 ;i<9;i++)
    {
        digitalWrite(i, hl[i-2]);
    }
}
void two()
{
    byte hl[7]={0,0,1,0,0,1,0};
    for(int i = 2 ;i<9;i++)
    {
        digitalWrite(i, hl[i-2]);
    }
}
void three()
{
    byte hl[7]={0,0,0,0,1,1,0};
    for(int i = 2 ;i<9;i++)
    {
        digitalWrite(i, hl[i-2]);
    }
}
void four()
{
    byte hl[7]={1,0,0,1,1,0,0};
    for(int i = 2 ;i<9;i++)
    {
        digitalWrite(i, hl[i-2]);
    }
}
void five()
{
    byte hl[7]={0,1,0,0,1,0,0};
    for(int i = 2 ;i<9;i++)
    {
        digitalWrite(i, hl[i-2]);
    }
}
void six()
{
    byte hl[7]={0,1,0,0,0,0,0};
    for(int i = 2 ;i<9;i++)
    {
        digitalWrite(i, hl[i-2]);
    }
}
void seven()
{
    byte hl[7]={0,0,0,1,1,1,1};
    for(int i = 2 ;i<9;i++)
    {
        digitalWrite(i, hl[i-2]);
    }
}
void eight()
{
    byte hl[7]={0,0,0,0,0,0,0};
    for(int i = 2 ;i<9;i++)
    {
        digitalWrite(i, hl[i-2]);
    }
}
void nine()
{
    byte hl[7]={0,0,0,0,1,0,0};
    for(int i = 2 ;i<9;i++)
    {
        digitalWrite(i, hl[i-2]);
    }
}
void zero()
{
    byte hl[7]={0,0,0,0,0,0,1};
    for(int i = 2 ;i<9;i++)
    {
        digitalWrite(i, hl[i-2]);
    }
}