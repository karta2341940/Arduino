#include <Keypad.h>
const byte rows = 4;
const byte cols = 4;
char hexakeys[rows][cols]={
    {'F','E','D','C'},
    {'B','3','6','9'},
    {'A','2','5','8'},
    {'0','1','4','7'}};
    
byte rowpin[rows]={25,24,23,22};
byte colpin[cols]={29,28,27,26};

Keypad keypad = Keypad( makeKeymap(hexakeys), rowpin , colpin , rows , cols );
void setup()
{
    Serial.begin(9600);
}
void loop()
{
    char ckey = keypad.getKey();
    if(ckey)
    {
        Serial.println(ckey);
    }
}