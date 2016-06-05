#ifndef PACKET_H
#define PACKET_H
// #include <Arduino.h>
#include "Cstring.h"
#include "StringStream.h"
#include "constants.h"
//#include <cstring>    //comment out when using arduino

class Packet
{
public:
    Packet();
    Packet(char msg[]);
//    Packet(char sender[],char recipient[], char command[], String other);
    Packet(char sender[],char recipient[], char command[], double other);
    void MakeNull();
    void MakeMessage(char sender[], char recip[], const char comm[]);
    void Read(char msg[]);
    void CamCoords(char Sendme[]);
    void BuildErrorPacket(char msg[]);
    char Message[101];
    char Sender[10];
    char Recipient[10];
    char Command[21];
    char Other[5][21];
    int otherUsed;

};

#endif // PACKET_H
