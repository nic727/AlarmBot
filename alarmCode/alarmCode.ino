
#include <Time.h>
#include <TimeLib.h>


int screaming = 0;

void setup()
{
  pinMode(1, OUTPUT);
  Serial.begin(115200); 
}

void loop()
{
  if (screaming){
    tones(1000);
  }
  Serial.println(sin(millis()*PI/1000)/2 + 0.5);
}

void tones(int delay){
  analogWrite(1, 2000);
  delayMicroseconds(sin(millis()*PI/1000)/2 + 0.5);
  analogWrite(1, 0);
  delayMicroseconds(sin(millis()*PI/1000)/2 + 0.5);
}

