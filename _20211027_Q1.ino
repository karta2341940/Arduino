//Arduino pin: 2,3,4,5,6,7,8 //def 7 seg led
#define CA1 30
#define CA2 31
#define CA3 32
int delay_time = 4;
byte segs[7]={2,3,4,5,6,7,8};
byte seven_seg_digits[16][7]=
{
  {0,0,0,0,0,0,1},
  {1,0,0,1,1,1,1},
  {0,0,1,0,0,1,0},
  {0,0,0,0,1,1,0},
  {1,0,0,1,1,0,0},
  {0,1,0,0,1,0,0},
  {0,1,0,0,0,0,0},
  {0,0,0,1,1,1,1},
  {0,0,0,0,0,0,0},
  {0,0,0,0,1,0,0},
  {0,0,0,1,0,0,0},//a
  {1,1,0,0,0,0,0},//b
  {0,1,1,0,0,0,1},//c
  {1,0,0,0,0,1,0},//d
  {0,1,1,0,0,0,0},//e
  {0,1,1,1,0,0,0},//f
};

  int redPin = 44;
  int grnPin= 45;
  int bluPin= 46;
  
void setup() {
  int i;
  for(i=2;i<=9;i++)
    pinMode(i,OUTPUT);
  digitalWrite(9,HIGH);
  pinMode(CA1,OUTPUT);
  pinMode(CA2,OUTPUT);
  pinMode(CA3,OUTPUT);
  pinMode(A13,OUTPUT);
  digitalWrite(A13,LOW);
  
  pinMode(redPin, OUTPUT);
  pinMode(grnPin, OUTPUT);
  pinMode(bluPin, OUTPUT);
}

void loop() {
     analogWrite(redPin,255);
     analogWrite(grnPin,255);
     analogWrite(bluPin,255);
     analogWrite(grnPin,0);
     
     for (int number = 10; number >=0; number--) {// 每一秒鐘計數一次/ 每一秒鐘計數一次
         unsigned long startTime = millis(); 
         for (unsigned long elapsed=0; elapsed < 1000; elapsed = millis() - startTime) {
//           lightDigit1(number%10);             //right 2
//           delay(delay_time); 
//           lightDigit2((number%60)/10);       //right 1
//            delay(delay_time);
           lightDigit4((number-number%10)/10);       //left 1
           delay(delay_time); 
           lightDigit3(number%10);       //left 2
           delay(delay_time);
           
      }
    }
    analogWrite(redPin, 0);
    delay(1000);
    analogWrite(grnPin, 255);
    for (int number = 10; number >=0; number--) {// 每一秒鐘計數一次/ 每一秒鐘計數一次
        unsigned long startTime = millis(); 
        for (unsigned long elapsed=0; elapsed < 1000; elapsed = millis() - startTime) {
        lightDigit2((number-number%10)/10);       //right 1
        delay(delay_time);
        lightDigit1(number%10);             //right 2
        delay(delay_time); 

            
//           lightDigit3(number%10);       //left 2
//           delay(delay_time);
//           lightDigit4((number/10);       //left 1
//           delay(delay_time);
      
     }
  }
}
void pickDigit(int x) {
  digitalWrite(CA1, HIGH);
  digitalWrite(CA2, HIGH);
  digitalWrite(CA3, HIGH);
  switch(x) {
    case 1: digitalWrite(CA1, LOW); digitalWrite(CA2, LOW);digitalWrite(CA3, LOW);break;
    case 2: digitalWrite(CA1, HIGH); digitalWrite(CA2, LOW);digitalWrite(CA3, LOW); break;
    case 3: digitalWrite(CA1, LOW); digitalWrite(CA2, HIGH);digitalWrite(CA3, LOW); break;
    case 4: digitalWrite(CA1, HIGH); digitalWrite(CA2, HIGH);digitalWrite(CA3, LOW); break;   
  }
}

void lightDigit1(byte number) {
  pickDigit(1);   
  lightSegments(number);  
}

void lightDigit2(byte number) {
  pickDigit(2);
  lightSegments(number);  
}

void lightDigit3(byte number) {
  pickDigit(3);
  lightSegments(number);  
}

void lightDigit4(byte number) {
  pickDigit(4);
  lightSegments(number);  
}

void lightSegments(byte number) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segs[i], seven_seg_digits[number][i]);
  }
}
