/**
 * @file setupCommunication.cpp
 * @author Antoni Wielgus
 * @date 04.10.2022
 */

#include "setup.h"


const int led = PC13;
const int RXPin = PA3;
const int TXPin = PA2;
const int DriveSerialBaudrate = 115200;
const int ComSerialBaudrate = 115200;

const int maxTasksAmount = 3;

Tasker tasker(maxTasksAmount);
ReceiveFrame frame;
HardwareSerial Serial2(RXPin, TXPin);
DriveCommunication driveSenderFrame(&Serial2);

class : public IExecutable
{
    void execute() override
    {
        frame.collectFrame();
    }
} receiveFrameTask;

class : public IExecutable
{
    void execute() override
    {
        if (frame.isConnection())
            digitalWrite(led, HIGH);
        else
            digitalWrite(led, LOW);
    }   
} blinkLedTask;

class : public IExecutable
{
    void execute() override
    {
        driveSenderFrame.updateFrame(frame.getDriveFrame(), frame.getDriveFrameSize());
        driveSenderFrame.sendFrame(); 
    }
} sendDriveFrame;

void setupCommunication()
{
    Serial.begin(ComSerialBaudrate);
    Serial2.begin(DriveSerialBaudrate);

    pinMode(led, OUTPUT);
    frame.ethernetInitialization();

    tasker.addTask_Hz(&receiveFrameTask, 100.f);
    tasker.addTask_Hz(&blinkLedTask, 100.f);
    tasker.addTask_Hz(&sendDriveFrame, 100.f);
}

