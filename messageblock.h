#ifndef MESSAGEBLOCK_H
#define MESSAGEBLOCK_H

#include <Arduino.h>
#include "../Cstring/Cstring.h"
#include "../StringStream/StringStream.h"
#include "../constants.h"



class MessageBlock
{
public:

    /*-----Constructors-----*/
    MessageBlock();
    MessageBlock(char msg[]);

    /*-----Functions-----*/
    void BreakDownMessage(char msg[]);
    void SendMessage(char toSend[]);
    void PrintToSerial();

    void CamCoors(char toSend[]);

    /*-----Variables that hold parts of the message-----*/
    char message[101];
    char sender[5];
    char receiver[5];
    char command[20];
    char other[5][20];

    /*-----Messages that change-----*/
//    char ConToCarNextPos[50]; //will give two positions. One is current other is destination
//    char CamToConLocation[50]; //will give current car location

//^^^^MAKE THESE FUNCTIONS^^^^^^

};

#endif // MESSAGEBLOCK_H
