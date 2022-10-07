/**
 * @file setupCommunication.cpp
 * @author Antoni Wielgus
 * @date 04.10.2022
 */

#include "setupCommunication.h"


const int led = PC13;

const int maxTasksAmount = 2;

Tasker tasker(maxTasksAmount);
ReceiveFrame frame;

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
        if (digitalRead(led) == HIGH)
            digitalWrite(led, LOW);
        else
            digitalWrite(led, HIGH);
    }
} blinkLedTask;

void setupCommunication()
{
    pinMode(led, OUTPUT);
    frame.ethernetInitialization();

    tasker.addTask_us(&receiveFrameTask, 10000L);
    tasker.addTask_us(&blinkLedTask, 1000000L);
}