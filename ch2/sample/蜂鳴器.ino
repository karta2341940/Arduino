#define output OUTPUT
#define input INPUT

int buzzer = A9;
int vrpin=A0;
int vrvalue=0;

void setup()
{
    pinMode(buzzer, output);
}
void loop()
{
    digitalWrite(buzzer,1);
    delay(1000);
    digitalWrite(buzzer,0);
    delay(1000);

}