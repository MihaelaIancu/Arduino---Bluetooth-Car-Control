#include <SoftwareSerial.h>

#define M1A 5
#define M1B 9 
#define M2A 4 
#define M2B 10

char command = '0';
//M1 e motorul drept
//M2 e motorul stang

SoftwareSerial BT(3, 2);

void fw();
void bw();
void left();
void right();
void stop();

void setup() {
  // put your setup code here, to run once:

  TCCR1B = TCCR1B & 0b11111000 | 0x04;

BT.begin(9600);
Serial.begin(9600);

pinMode(M1A, OUTPUT);
pinMode(M2A, OUTPUT);
pinMode(M1B, OUTPUT);
pinMode(M2B, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
//fw();

//  digitalWrite(M1A, LOW);
//  digitalWrite(M1B, HIGH);
//
//  digitalWrite(M2A, LOW);
//  digitalWrite(M2B, HIGH);
//
if(BT.available())
{
  char input = BT.read();
  if (input != "\n")
    command = input;
  Serial.println(input);
  switch(command){
    case '1':
      Serial.println("hei");
      fw();
      break;
    case '2':
      bw();
      break;
    case '3':
      left();
      break;
    case '4':
      right();
      break;
    case '0':
      stop();
      break;
  
}
  
  
  
}
}

void fw()
{
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, HIGH);

  digitalWrite(M2A, LOW);
  digitalWrite(M2B, HIGH);
}

void bw()
{
  digitalWrite(M1A, 1);
  analogWrite(M1B, (255-255));

  digitalWrite(M2A, 1);
  analogWrite(M2B, (255-255));
  
}

void left()
{
  digitalWrite(M1A, 0);
  analogWrite(M1B, 100);

  digitalWrite(M2A, 1);
  analogWrite(M2B, (255-75));
  
}

void right()
{
  digitalWrite(M1A, 1);
  analogWrite(M1B, (255-75));

  digitalWrite(M2A, 0);
  analogWrite(M2B, 100);
  
}

void stop()
{
  digitalWrite(M1A, 0);
  analogWrite(M1B, 0);

  digitalWrite(M2A, 0);
  analogWrite(M2B, 0);
  
}
