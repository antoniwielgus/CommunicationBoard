#include <Arduino.h>
#include "receiveFrame.h"

ReceiveFrame myFrame;

void setup() 
{
  myFrame.ethernetInitialization();

  Serial.begin(9600);

}

void loop() 
{
  myFrame.collectFrame();

  uint8_t* firstByte = myFrame.getDriveBits();

  Serial.println(myFrame.getDriveBits()[1]);
}
  