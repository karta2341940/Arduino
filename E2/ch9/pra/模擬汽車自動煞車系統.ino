#define trig 12
#define echo 13
#define low LOW
#define high HIGH
#define output OUTPUT
#define input INPUT
const int moto1 = 2 ;
const int moto2 = 3 ;



#include <LiquidCrystal.h>
LiquidCrystal lcd(49,48,47,43,42,41);

long ping(){
    digitalWrite(trig, low);
    delayMicroseconds(12);
    digitalWrite(trig,high);
    delayMicroseconds(10);
    digitalWrite(trig, low);
    return pulseIn(echo,high);
}

void setup(){
    pinMode(moto1, output);
    pinMode(moto2, output);
    pinMode(trig, output);
    pinMode(echo, input);
    digitalWrite(moto2, low);

    Serial.begin(9600);
    lcd.begin(16,2);
    lcd.print("Distance: cm");
}

void loop(){
    long duration,cm;
    String result = "Distance: ";
    duration = ping();
    cm = duration/58;
    result+=cm;
    result+="(cm)";
    Serial.println(result);
    lcd.setCursor(0,0);
    lcd.print("Distance:         cm");
    lcd.setCursor(9,0);
    lcd.print(cm);
        
    if(cm>3 && cm<30){
        analogWrite(moto1,(cm*12)%255);
    }
    else {
        digitalWrite(moto1, low);
        digitalWrite(moto2, low);
    }
    delay(500);

}

void backward()
{
    digitalWrite(moto1, low);
    digitalWrite(moto2, high);
}