#define out OUTPUT
#define in INPUT

int buzzer =A9;
int vrpin = A0;
int vrvalue = 0;
void setup()
{
    pinMode(buzzer, OUTPUT);
    pinMode(vrpin, in);
}
void loop()
{
    vrvalue = analogRead(vrpin);
    digitalWrite(buzzer, 1);
    delay(vrvalue);
    digitalWrite(buzzer, 0);
    delay(vrvalue);
}