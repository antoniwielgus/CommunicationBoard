/**
 * @file receiveFrame.h
 * @author Antoni wielgus
 * @date 02.10.2022
 */

//this class enable receive frame from udp

#ifndef RECEIVE_FRAME
#define RECEIVE_FRAME

#include <Arduino.h>
#include <SPI.h>
#include <EthernetUdp.h>
#include <HardwareSerial.h>


class ControlPanelCommunication
{
private:
    static const uint8_t macAddressArraySize = 6;
    uint8_t mac[macAddressArraySize];
    IPAddress ip;
    uint16_t localPort;

    static const uint16_t receiveFrameSize = 320; //size of frame to collect
    uint8_t frame[receiveFrameSize];
    
    static const uint8_t wheelsAmount = 6;
    static const uint8_t driveFrameSize = 12;
    uint8_t driveFrame[driveFrameSize];

    EthernetUDP Udp;

    uint32_t lastReceivedFrameTime_ms = 0;
    static const uint32_t CommLostTimeout_ms = 2000;

    void insertDriveBytesToArray();
    void insertManipulatorBytesToArray(); //to do
    void insertBiologyBytesToArray(); //to do

public:
    void ethernetInitialization(); //cetting ip and other necessery things

    void collectFrame();

    void setIPAdress(IPAddress ip = IPAddress(192, 168, 1, 10));
    void setLocalPort(uint16_t localPort = 5150);
    void initSPI(uint8_t MISO_pin = PB4, uint8_t MOSI_pin = PB5, uint8_t SCLK_pin = PB3, uint8_t SS_pin = PA15);
    void initMacArray();
    void initEthernet();

    IPAddress getIPAdress();
    uint16_t getLocalPort();
    uint16_t getReceiveFrameSize();
    uint8_t getDriveFrameSize();
    uint8_t* getDriveFrame();
    uint8_t getManipulatorFrameSize(); //to do
    uint8_t* getManipulatorFrame(); //to do
    uint8_t getBiologyFrameSize(); //to do
    uint8_t* getBiologyFrame(); //to do

    void showOnSerialDriveBytes(HardwareSerial* serialPort);

    bool isConnection(); //check whether this function work properly
};

#endif
