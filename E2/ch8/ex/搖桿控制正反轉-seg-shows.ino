int joyx =A1;
int joyy=A2;
int sw = A3;
int y0=0;
int swstate=0;
const int moto1 = 2 ;
const int moto2 = 3 ;
const int Delay = 1000;
#define output OUTPUT
#define input INPUT
#define high HIGH
#define low LOW
int taimu=0;
#include <LiquidCrystal.h>
LiquidCrystal lcd(49,48,47,43,42,41);
void setup()
{
    Serial.begin(9600);
    pinMode(sw, INPUT_PULLUP);
    pinMode(moto1, output);
    pinMode(moto2, output);
    lcd.begin(0,0);
    y0=analogRead(joyy);

}
void loop()
{
    lcd.setCursor(0,0);
    lcd.print((taimu/10)%10);
    delay(100);
    int x,y,value;
    value = analogRead(joyy);
    y=value-y0;
    swstate=digitalRead(sw);
    Serial.print(y);
    if(y>100)
    {
        forward();
        taimu++;
    }
    else if(y < -100)
    {
        backward();
        taimu++;
    }
    else 
    {
        motorstop();
        lcd.print("        ");
        taimu=0;
    }
    
    
    
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

