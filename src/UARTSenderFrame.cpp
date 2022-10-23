/**
 * @file UARTSenderFrame.cpp
 * @author Antoni Wielgus
 * @date 07.10.2022
 */

#include "UARTSenderFrame.h"

UARTSenderFrame::UARTSenderFrame(uint8_t frameSize, HardwareSerial* mySerial)
{
    this->frameSize = frameSize;
    this->mySerial = mySerial;

    frame = new uint8_t[this->frameSize];
}

UARTSenderFrame::~UARTSenderFrame()
{
    delete [] frame;
}

uint8_t UARTSenderFrame::sendFrame(uint8_t* _frame)
{
    uint8_t buffer[3];
    buffer[0] = 1;
    buffer[1] = 2;
    buffer[2] = 5;

    // if (mySerial->available() >= frameSize)
    // {
        return mySerial->write(_frame, frameSize);

        // return mySerial->write("kochamOleMaz");

    //     return true;
    // // }

    // return false;
}