const int moto1 = 2 ;
const int moto2 = 3 ;
const int Delay = 1000;
#define output OUTPUT
#define input INPUT
#define high HIGH
#define low LOW

void setup()
{
    pinMode(moto1, output);
    pinMode(moto2, output);
}
void loop()
{
    forward();
    delay(Delay);
    motorstop();
    delay(500);
    backward();
    delay(Delay);
    motorstop();
    delay(500);

}
void motorstop()
{
    digitalWrite(moto1, low);
    digitalWrite(moto2, low);
}
void forward()
{
    digitalWrite(moto1, high);
    digitalWrite(moto2, low);
}
void backward()
{
    digitalWrite(moto1, low);
    digitalWrite(moto2, high);
}





