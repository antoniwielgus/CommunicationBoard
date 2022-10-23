/**
 * @file setupCommunication.cpp
 * @author Antoni Wielgus
 * @date 04.10.2022
 */

#include "setupCommunication.h"


const int led = PC13;
const int RXPin = PA3;
const int TXPin = PA2;
const int serila2Baudrate = 9600;
const int serialBaudrate = 9600;

const int maxTasksAmount = 3;

Tasker tasker(maxTasksAmount);
ReceiveFrame frame;
UARTSenderFrame senderFrame(frame.getDriveFrameSize(), &Serial2);
HardwareSerial Serial2(RXPin, TXPin);

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
        senderFrame.sendFrame(frame.getDriveBits());

        for (int i = 0; i < frame.getDriveFrameSize(); i++)
        {
            Serial.print(frame.getDriveBits()[i]);
            Serial.print(" ");
        }

        Serial.println();
    }
} sendDriveFrame;

void setupCommunication()
{
    Serial.begin(serialBaudrate);
    Serial2.begin(serila2Baudrate);

    pinMode(led, OUTPUT);
    frame.ethernetInitialization();

    tasker.addTask_us(&receiveFrameTask, 100000);
    tasker.addTask_us(&blinkLedTask, 100000);
    tasker.addTask_us(&sendDriveFrame, 50000);
}