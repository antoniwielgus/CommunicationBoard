/**
 * @file setupCommunication.h
 * @author Antoni Wielgus
 * @date 04.10.2022
 */

#ifndef SETUP_COMMUNICATION
#define SETUP_COMMUNICATION

#include "Tasker.h"
#include "receiveFrame.h"
#include "UARTSenderFrame.h"

extern Tasker tasker;
extern ReceiveFrame frame;
extern UARTSenderFrame senderFrame;
extern HardwareSerial Serial2;

void setupCommunication();

#endif