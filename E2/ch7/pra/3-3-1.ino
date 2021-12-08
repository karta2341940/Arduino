int pin = A6;
int value = 0;
void setup()
{
    Serial.begin( 9600);
}
void loop()
{
    value = analogRead(pin);
    Serial.print("Value = ");
    Serial.println(value);
    delay(10);
}