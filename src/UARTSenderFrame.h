/**
 * @file UARTSenderFrame.h
 * @author Antoni Wielgus
 * @date 07.10.2022
 */

#ifndef UART_SENDER_FRAME
#define UART_SENDER_FRAME

#include <HardwareSerial.h>


class UARTSenderFrame
{
private:
    uint8_t frameSize;
    uint8_t* frame;
    HardwareSerial* mySerial;

public:
    UARTSenderFrame(uint8_t frameSize, HardwareSerial* mySerial);
    ~UARTSenderFrame();

    void loadDataToFrame(uint8_t*);
    uint8_t getFrameSize();
    uint8_t sendFrame(uint8_t* _frame);
};

#endif