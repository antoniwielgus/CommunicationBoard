#include <Arduino.h>
//#include "receiveFrame.h"
#include "setupCommunication.h"

//ReceiveFrame frame;
const int led = PC13;

void setup() 
{
  // frame.ethernetInitialization();

  setupCommunication();


  Serial.begin(9600);
  pinMode(led, OUTPUT);

}

void loop() 
{
  tasker.loop();

  // if (digitalRead(led) == HIGH)
  //   digitalWrite(led, LOW);
  // else
  //   digitalWrite(led, HIGH);

  // delay(1000);

  // if (frame.isConnection() == false)
  // {
  //   digitalWrite(led, LOW);
  //   delay(10);
  // }
  // else
  // {
  //   digitalWrite(led, HIGH);
  //   delay(10);
  // }
    
  // delay(50);

  // //Serial.println(frame.isConnection());

  // frame.collectFrame();

  // uint8_t* firstByte = frame.getDriveBits();

  // //frame.showOnSerialDriveBytes(&Serial);
}
  