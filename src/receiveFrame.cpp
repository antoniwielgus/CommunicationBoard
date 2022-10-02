/**
 * @file receiveFrame.cpp
 * @author Antoni Wielgus
 * @date 02.10.2022
 */

#include <receiveFrame.h>


void ReceiveFrame::insertDriveBytesToArray()
{
    uint16_t index = 4;

    for(uint8_t i = 0; i < driveFrameSize; ++i)
        driveFrame[i] = frame[index++];
}

void ReceiveFrame::collectFrame()
{
    uint16_t packetSize = Udp.parsePacket();

    if (packetSize != receiveFrameSize)
        return;

    Udp.read(frame, packetSize);

    insertDriveBytesToArray();
}

void ReceiveFrame::ethernetInitialization()
{
    setIPAdress();
    setLocalPort();
    initSPI();
    initMacArray();
    initEthernet();
}

void ReceiveFrame::setIPAdress(IPAddress ip)
{
    this->ip = ip;
}

void ReceiveFrame::setLocalPort(uint16_t localPort)
{
    this->localPort = localPort;
}

void ReceiveFrame::initSPI(uint8_t MISO_pin, uint8_t MOSI_pin, uint8_t SCLK_pin, uint8_t SS_pin)
{
    SPI.setMISO(MISO_pin);
    SPI.setMOSI(MOSI_pin);
    SPI.setSCLK(SCLK_pin);
    Ethernet.init(SS_pin); //set SS pin
}

void ReceiveFrame::initMacArray()
{
    mac[0] = 0xDE;
    mac[1] = 0xAD;
    mac[2] = 0xBE;
    mac[3] = 0xEF;
    mac[4] = 0xFE;
    mac[5] = 0xED;
}

void ReceiveFrame::initEthernet()
{
    Ethernet.begin(mac, ip);
    Udp.begin(localPort);
}

IPAddress ReceiveFrame::getIPAdress()
{
    return ip;
}

uint16_t ReceiveFrame::getLocalPort()
{
    return localPort;
}

uint16_t ReceiveFrame::getReceiveFrameSize()
{
    return receiveFrameSize;
}

uint8_t ReceiveFrame::getDriveFrameSize()
{
    return driveFrameSize;
}

uint8_t* ReceiveFrame::getDriveBits()
{
    return driveFrame;
}

void showOnSerialDriveBytes()
{
    Serial.println("Dziala printowanie!");
}

