#include "messageblock.h"

MessageBlock::MessageBlock(){
    for (int i = 0; i<100; i++){
        //        cout<<"MessageBlock ctor without message!!"<<endl;
        Serial.println("MessageBlock ctor without message!!");
    }
}

MessageBlock::MessageBlock(char msg[])
{
    strCpy(message,msg);
    BreakDownMessage(msg);
    //    PrintToSerial();
}

void MessageBlock::BreakDownMessage(char msg[])
{
    StringStream stream(msg);

    char next[50]="?";
    //    for(int i=0;!strCmp(next,"}");i++){
    for(int i = 0; !stream.endOfStr(); i++){
        stream.getNext(next);
//        Serial.print("next: ");
//        Serial.println(next);
        switch(i){
        case 0:
            break;
        case 1:strCpy(sender,next);
            break;
        case 2:strCpy(receiver,next);
            break;
        case 3:strCpy(command,next);
            break;
        default:strCpy(other[i-4],next);
            // why is this i-4....?
            break;
        }
    }
}

//takes the message and constructs a response message to send back
void MessageBlock::SendMessage(char toSend[])
{

    if(strCmp(receiver, "Car")){

        Serial.println("Car");

        if(command, "TurnLightOn"){
            Serial.println("TurnLightOn");
            strCpy(toSend,CAR_CON_LIGHT_ON);
            Serial.println(toSend);

        }

        if (strCmp(command, "GoTo")){
            Serial.println("GoTo");

            //current location given in message
            //Go(x,y);
            //car moving

            strCpy(toSend,CAR_CON_REACHED_DEST);

            Serial.println(toSend);

        }
    }

    else if (strCmp(receiver, "Cam")){
        Serial.println("Cam");
        if(strCmp(command, "ReqPosition")){
            Serial.println("ReqPosition");

            //get position of specified car

            CamCoors(toSend);

            Serial.println(toSend);
        }
    }

    //actually send the toSend to the client:
    //        client.print(toSend);     //can't print to client from class, won't have appropriate initialization

    //        Serial.print(X1);Serial.print(" ");Serial.print(Y1);
}
//printing to ensure everything was broken up properly and saved in the MessageBlock
void MessageBlock::PrintToSerial()
{
    Serial.print("message: [");
    Serial.print(message);
    Serial.println("]");

    Serial.print("[");
    Serial.print(sender);
    Serial.print("] -> [");
    Serial.print(receiver);
    Serial.print("]: [");
    Serial.print(command);
    Serial.println("]");

    if(!strCmp(other[0],"}")){
        Serial.print("Coordinates: ");
        for(int i = 0; !strCmp(other[i], "}") || i < 4; i++){
            Serial.print("(");
            Serial.print(other[i]);
            i++;
            Serial.print(",");
            Serial.print(other[i]);
            Serial.print(")");
        }
        Serial.println();
    }

    //    cout<< "message: [" << message << "]" << endl
    //        << "[" << sender << "] -> [" << receiver << "]: [" << command << "]" << endl;
    //    for(int i = 0; !strCmp(other[i],"}"); i++){
    //        cout << "[" << other[i] << "]" << endl;
    //    }
}

void MessageBlock::CamCoors(char toSend[]){
    strCpy(toSend, "{ Cam Con Location ");
//    append(toSend, "x1 y1 }", 7);
}

