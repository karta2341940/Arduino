int pin = A6;
int value = 0;
int ledpin =3;
#define output OUTPUT
#define low LOW
void setup()
{
    pinMode(ledpin, output);
    pinMode(A15, output);
    digitalWrite(A15, low);
}
void loop()
{
    value = analogRead(pin);
    analogWrite(ledpin, value/4);
}