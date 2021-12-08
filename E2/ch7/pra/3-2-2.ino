int base = 2 ;
int num = 8 ;
int bri = 0 ;
int fade = 5 ;
#define output OUTPUT
#define low LOW

void setup()
{

    for( int i  = 0 ; i <= base ; i ++)
    {
        pinMode(i, output);
    }
    pinMode(A15, output);
    digitalWrite(A15, low);
}

void loop()
{
    for( int  i = base ; i < base +num ; i ++ )
    {
        analogWrite(i, bri);
    }
    bri = bri+fade;
    if( bri <= 0 || bri >= 255 )
    {
        fade = -fade ;
    }
    delay(20);
}