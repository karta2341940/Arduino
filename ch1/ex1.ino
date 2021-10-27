byte ssd[10][7]=
{
  {0,0,0,0,0,0,1},//0
  {1,0,0,1,1,1,1},//1
  {0,0,1,0,0,1,0},//2
  {0,0,0,0,1,1,0},//3
  {1,0,0,1,1,0,0},//4
  {0,1,0,0,1,0,0},//5
  {0,1,0,0,0,0,0},//6
  {0,0,0,1,1,1,1},//7
  {0,0,0,0,0,0,0},//8
  {0,0,0,1,1,0,0}//9
};

void setup() 
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  writeDot(1);
  pinMode(A13, OUTPUT);
  digitalWrite(A13, LOW);
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);
  digitalWrite(30, LOW);
  digitalWrite(31, LOW);
  digitalWrite(32, LOW);
}

void writeDot(byte dot)
{
    digitalWrite(9, dot);
}
void ssw(byte digit)
{
  byte pin =2 ;
  for(byte i=0 ; i< 7 ; i++)
  {
    digitalWrite(pin, ssd[digit][i]);
    ++pin;
  }
}

void loop() {
  // put your main code here, to run repeatedly: 
  for(byte i= 0 ; i< 10 ;i++)
  {
    delay(500);
    ssw(i);
  }
}

