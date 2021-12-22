#define trig 12
#define echo 13
#define low LOW
#define high HIGH
#define output OUTPUT
#define input INPUT


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
    pinMode(trig, output);
    pinMode(echo, input);
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
    delay(500);

}

