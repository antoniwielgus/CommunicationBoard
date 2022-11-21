/**
 * @file setupCommunication.h
 * @author Antoni Wielgus
 * @date 04.10.2022
 */

//this class is to manage frame

#ifndef SETUP_COMMUNICATION
#define SETUP_COMMUNICATION

#include "Tasker.h"
#include "receiveFrame.h"
#include "DriveSenderFrame.h"

extern Tasker tasker;
extern ReceiveFrame frame;
extern HardwareSerial Serial2;
extern DriveSenderFrame driveSenderFrame;

void setupCommunication();

#endif

