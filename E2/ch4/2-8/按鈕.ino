#define otp OUTPUT
#define inp INPUT
int base =6 ;
int base1 = 33;
int num = 4 ;
int dipsw[4]={0};

void setup()
{
    for( int i = base ; i < base+num ; i+=1 )
    {
        pinMode( i , otp );
    }
    for( int i = base1 ; i < base1+num ; i+=1 )
    {
        pinMode( i , INPUT_PULLUP );
    }
    pinMode( A15 , otp );
    digitalWrite( A15 , 0);
}
void loop()
{
    for( int i = 0 ; i < 4 ; i += 1)
    {
        dipsw[i] = digitalRead(base1+i);
        digitalWrite( 9-i , dipsw[i]);
    }
}


