/**
 * @file setupCommunication.cpp
 * @author Antoni Wielgus
 * @date 04.10.2022
 */

#include "setup.h"


const int ControlPanelCommStatusLed = PC13;
const int RXPin = PA3;
const int TXPin = PA2;
const int DriveSerialBaudrate = 115200;
const int ComSerialBaudrate = 115200;

const int maxTasksAmount = 3;

Tasker tasker(maxTasksAmount);
ControlPanelCommunication controlPanelCommunication;
HardwareSerial Serial2(RXPin, TXPin);
PacketComm::StreamComm<MaxBufferSize> driveCommunication(&Serial2);

class : public IExecutable
{
    void execute() override
    {
        // receive from control panel
        controlPanelCommunication.collectFrame();

        // send to drive
        if (controlPanelCommunication.isConnection())
        {
            driveCommunication.send(controlPanelCommunication.getDriveFrame(), controlPanelCommunication.getDriveFrameSize());
        }
    }
} controlPanelReceiveTask;

class : public IExecutable
{
    void execute() override
    {
        digitalWrite(ControlPanelCommStatusLed, !controlPanelCommunication.isConnection());
    }
} StatusLedTask;

void setupCommunication()
{
    Serial.begin(ComSerialBaudrate);
    Serial2.begin(DriveSerialBaudrate);

    pinMode(ControlPanelCommStatusLed, OUTPUT);
    controlPanelCommunication.ethernetInitialization();

    tasker.addTask_Hz(&controlPanelReceiveTask, 100.f);
    tasker.addTask_Hz(&StatusLedTask, 5.f);
}

