/**
 * @file UARTSenderFrame.h
 * @author Antoni Wielgus
 * @date 07.10.2022
 */

//this class represent frame to send and contain method to send
//firstly setup Serial2 (rx, tx and baudrate)

//firstly use "updateFrame" function and nex to "sendFrame"

#ifndef UART_SENDER_FRAME
#define UART_SENDER_FRAME

#include <HardwareSerial.h>
#include <LowLevelImpl/StreamComm.h>
#include <DataPacket.h>
#include <cstdint>


class DriveSenderFrame
{
private:
    static const uint8_t MaxBufferSize = 15;
    PacketComm::StreamComm <MaxBufferSize> streamComm;

    static const size_t frameSize = 12;
    uint8_t frame[frameSize];

public:
    DriveSenderFrame(HardwareSerial* _serial);

    void updateFrame(const uint8_t* _frame, uint8_t _frameSize);
    void sendFrame();
};

#endif