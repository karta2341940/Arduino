#include <LiquidCrystal.h>
int px =A1;
int py =A2;
int sw =A3;
int value = 0;
int x0 =0;
int y0 =0;
int swstate =0;
LiquidCrystal lcd(49,48,47,43,42,41);

void setup()
{
    pinMode(sw, INPUT_PULLUP);
    y0 = analogRead(py);
    x0 = analogRead(px);
    lcd.begin(16,2);
}

void loop()
{
    int x,y,value;
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("X=      Y=   ");
    lcd.setCursor(0,1);
    lcd.print("SW=");
    value=analogRead(px);
    x=value-x0;
    value=analogRead(py);
    y=value-y0;
    swstate=digitalRead(sw);
    
    lcd.setCursor(2,0);
    lcd.print(x);


    lcd.setCursor(10,0);
    lcd.print(y);
    
    lcd.setCursor(3,1);
    lcd.print(swstate);
    
    delay(100);



}