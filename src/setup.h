/**
 * @file setupCommunication.h
 * @author Antoni Wielgus
 * @date 04.10.2022
 */

//this class is to manage frame

#ifndef SETUP_COMMUNICATION
#define SETUP_COMMUNICATION

#include "Tasker.h"
#include "ControlPanelCommunication.h"
#include "DriveCommunication.h"

extern Tasker tasker;
extern ControlPanelCommunication controlPanelCommunication;
extern HardwareSerial Serial2;
extern DriveCommunication driveCommunication;

void setupCommunication();

#endif

