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
#include <LowLevelImpl/StreamComm.h>

const uint8_t MaxBufferSize = 15;

extern Tasker tasker;
extern ControlPanelCommunication controlPanelCommunication;
extern HardwareSerial Serial2;
extern PacketComm::StreamComm<MaxBufferSize> driveCommunication;

void setupCommunication();

#endif

