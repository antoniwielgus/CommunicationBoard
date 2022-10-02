/**
 * @file receiveFrame.h
 * @author Antoni wielgus
 * @date 02.10.2022
 */

#ifndef RECEIVE_FRAME
#define RECEIVE_FRAME

#include <Arduino.h>
#include <SPI.h>
#include <EthernetUdp.h>
#include <HardwareSerial.h>


class ReceiveFrame
{
private:
    static const uint8_t macAddressArraySize = 6;
    uint8_t mac[macAddressArraySize];
    IPAddress ip;
    uint16_t localPort;

    static const uint16_t receiveFrameSize = 320;
    uint8_t frame[receiveFrameSize];
    
    static const uint8_t wheelsAmount = 6;
    static const uint8_t driveFrameSize = 12;
    uint8_t driveFrame[driveFrameSize];

    EthernetUDP Udp;

    void insertDriveBytesToArray();

public:
    void collectFrame();

    void ethernetInitialization();

    void setIPAdress(IPAddress ip = IPAddress(192, 168, 1, 10));
    void setLocalPort(uint16_t localPort = 5150);

    void initSPI(uint8_t MISO_pin = PB4, uint8_t MOSI_pin = PB5, uint8_t SCLK_pin = PB3, uint8_t SS_pin = PA15);
    void initMacArray();
    void initEthernet();

    IPAddress getIPAdress();
    uint16_t getLocalPort();
    uint16_t getReceiveFrameSize();
    uint8_t getDriveFrameSize();
    uint8_t* getDriveBits();

    void showOnSerialDriveBytes();
};

#endif
