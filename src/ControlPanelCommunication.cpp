/**
 * @file receiveFrame.cpp
 * @author Antoni Wielgus
 * @date 02.10.2022
 */

#include <ControlPanelCommunication.h>


void ControlPanelCommunication::insertDriveBytesToArray()
{
    uint16_t index = 4;

    for(uint8_t i = 0; i < driveFrameSize; ++i)
        driveFrame[i] = frame[index++];
}

void ControlPanelCommunication::collectFrame()
{
    uint16_t packetSize = Udp.parsePacket();

    if (packetSize != receiveFrameSize)
        return;

    Udp.read(frame, packetSize);
    insertDriveBytesToArray();
    lastReceivedFrameTime_ms = millis();
}

void ControlPanelCommunication::ethernetInitialization()
{
    setIPAdress();
    setLocalPort();
    initSPI();
    initMacArray();
    initEthernet();
}

void ControlPanelCommunication::setIPAdress(IPAddress ip)
{
    this->ip = ip;
}

void ControlPanelCommunication::setLocalPort(uint16_t localPort)
{
    this->localPort = localPort;
}

void ControlPanelCommunication::initSPI(uint8_t MISO_pin, uint8_t MOSI_pin, uint8_t SCLK_pin, uint8_t SS_pin)
{
    SPI.setMISO(MISO_pin);
    SPI.setMOSI(MOSI_pin);
    SPI.setSCLK(SCLK_pin);
    Ethernet.init(SS_pin); //set SS pin
}

void ControlPanelCommunication::initMacArray()
{
    mac[0] = 0xDE;
    mac[1] = 0xAD;
    mac[2] = 0xBE;
    mac[3] = 0xEF;
    mac[4] = 0xFE;
    mac[5] = 0xED;
}

void ControlPanelCommunication::initEthernet()
{
    Ethernet.begin(mac, ip);
    Udp.begin(localPort);
}

IPAddress ControlPanelCommunication::getIPAdress()
{
    return ip;
}

uint16_t ControlPanelCommunication::getLocalPort()
{
    return localPort;
}

uint16_t ControlPanelCommunication::getReceiveFrameSize()
{
    return receiveFrameSize;
}

uint8_t ControlPanelCommunication::getDriveFrameSize()
{
    return driveFrameSize;
}

uint8_t* ControlPanelCommunication::getDriveFrame()
{
    return driveFrame;
}

void ControlPanelCommunication::showOnSerialDriveBytes(HardwareSerial* serialPort)
{
    for (int i = 0; i < driveFrameSize; ++i)
    {
        serialPort->print(driveFrame[i]);
        serialPort->print(" ");
    }

    serialPort->println();
}

bool ControlPanelCommunication::isConnection()
{
    return ((millis() - lastReceivedFrameTime_ms) < LostCommTimeout_ms);
}

