/**
 * @file UARTSenderFrame.cpp
 * @author Antoni Wielgus
 * @date 07.10.2022
 */

#include "DriveCommunication.h"

DriveCommunication::DriveCommunication(HardwareSerial* _serial) : streamComm(_serial)
{
}

void DriveCommunication::updateFrame(const uint8_t *_frame, uint8_t _frameSize)
{
    if (_frameSize != frameSize)
        return;

    for (uint8_t i = 0; i < _frameSize; ++i)
        frame[i] = _frame[i];
}

void DriveCommunication::sendFrame()
{
    streamComm.send(frame, frameSize);

    // if (mySerial->available() >= frameSize)
    // {
    // return mySerial->write(_frame, frameSize);

    // return mySerial->write("kochamOleMaz");

    //     return true;
    // // }

    // return false;
}