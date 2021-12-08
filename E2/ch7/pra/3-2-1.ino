int brightness = 0 ;
int fade=5;
int delayduration = 20;
#define output OUTPUT
#define low LOW

void setup()
{
    pinMode(2, output);
    pinMode(A15, output);
    digitalWrite(A15, low);
}

void loop()
{
    analogWrite(2, brightness);
    brightness = brightness + fade;
    if( brightness <= 0 || brightness >= 255 )
    {  
        fade = -fade;       
    }
    delay( delayduration );
}