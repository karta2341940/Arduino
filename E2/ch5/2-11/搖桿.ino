int joyx =A1;
int joyy=A2;
int sw = A3;
int x0=0;
int y0=0;
int swstate=0;
void setup()
{
    Serial.begin(9600);
    pinMode(sw, INPUT_PULLUP);
    y0=analogRead(joyy);
    x0=analogRead(joyx);
}
void loop()
{
    int x,y,value;
    value =analogRead(joyx);
    x=value-x0;
    value = analogRead(joyy);
    y=value-y0;
    swstate=digitalRead(sw);
    Serial.println(" X = ");
    Serial.println(x);
    Serial.println(" Y = ");
    Serial.println(y);
    Serial.println(" SW = ");
    Serial.println(swstate);
    delay(20);
}



