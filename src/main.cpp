#include <Arduino.h>
#include "setupCommunication.h"

uint8_t arrayyy[12];

void setup() 
{
  setupCommunication();
}

void loop() 
{
  tasker.loop();
}
  