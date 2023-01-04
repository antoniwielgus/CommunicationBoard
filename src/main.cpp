#include <Arduino.h>
#include "setup.h"

void setup() 
{
  setupCommunication();
}

void loop() 
{
  tasker.loop();
}
  