#define output OUTPUT
#define low LOW
#define high HIGH
int r5 = A4;
void setup(){
    pinMode(r5, output);
    digitalWrite(r5, 0);
}
void loop(){
    digitalWrite(r5, 1);
    delay(1000);
    digitalWrite(r5, 0);
    delay(1000);
}