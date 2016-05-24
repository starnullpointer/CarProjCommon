#include "Packet.h"

Packet::Packet()
{
    MakeNull();
    BuildErrorPacket("Error_Zero_arg_constructor");
}
Packet::Packet(char msg[]):otherUsed(0)
{
    MakeNull();
    strCpy(Message,msg);
    int length= strLen(msg);
    //length -1 because of null at the end
    if(length<100){
        if(Message[0]=='{' && Message[length-1]=='}'){
            Read(msg);
        }
        else{
            BuildErrorPacket("Error_No_braces");
        }
    } else {
        BuildErrorPacket("Error_Message_too_long");
    }

}

void Packet::MakeNull(){
    Message[0] = '\0';
    Command[0] = '\0';
    otherUsed = 0;
    Sender[0] = '\0';
    Recipient[0] = '\0';
}

void Packet::MakeMessage(char sender[], char recip[], const char comm[]/*, char other[5][], int o_used*/){
    // takes one string taking all the variable
    // ignoring other momentarily, might need it later...
    strCpy(Sender, sender);
    strCpy(Recipient, recip);
    strCpy(Command, comm);
//    otherUsed = o_used;
    Message[0]='{';
    Message[1]='\0';
    append(Message," ");
    append(Message, Sender);
    append(Message," ");
    append(Message, Recipient);
    append(Message," ");
    append(Message, Command);
    append(Message," ");
    for(int i=0; i<otherUsed; i++){
//        Other[i][0] = other[i][0];
        append(Message,Other[i]);
        append(Message," ");
    }
    append(Message, "}"); //spaces before and after brace
}

//Packet::Packet(char sender[], char recipient[], char command[],
//    String other):otherUsed(0)
//{
//    int other_len= other.length()+1;
//    if(other_len>100){
//        BuildErrorPacket("Error_other_too_long");
//        return;
//    }

//    char coord[101];
//    other.toCharArray(coord, other_len); //takes received and turns it into a char array message
//    char copy[101];
//    StringStream coor_str(coord);
//    int count;
//    for(int i = 0; !coor_str.endOfStr(); i++){
//        if(i>=5){
//            BuildErrorPacket("Error_Too_many_others");
//            return;
//        }
//        coor_str.getNext(copy);
//        if(strLen(copy)>20){
//            BuildErrorPacket("Error_Copy_too_long");
//            return;
//        }

//        strCpy(Other[i],copy);
//        count=i;
//    }

//    otherUsed=count;
//    strCpy(Sender,sender);
//    strCpy(Recipient,recipient);
//    strCpy(Command,command);

//    //creating a char message array

////    append(Message, "{ ");
//    Message[0]='{';
//    Message[1]='\0';
//    append(Message," ");
//    append(Message, Sender);
//    append(Message," ");
//    append(Message, Recipient);
//    append(Message," ");
//    append(Message, Command);
//    append(Message," ");
//    for(int i=0; i<otherUsed; i++){
//        append(Message,Other[i]);
//        append(Message," ");
//    }
//    append(Message, "}"); //spaces before and after brace
//    Serial.println(Message);
////    Write(Message);
//}

Packet::Packet(char sender[],char recipient[], char command[], double other)
{
    MakeNull();
    BuildErrorPacket("Error_Joe_build_this");
}

void Packet::Read(char msg[])
{
    //msg can't be more than 100. already checked
    StringStream stream(msg);

    char next[50]="?";
    //    for(int i=0;!strCmp(next,"}");i++){
    for(int i = 0; !stream.endOfStr(); i++){
        stream.getNext(next);
//        Serial.print("next: ");
//        Serial.println(next);
        switch(i){
        case 0: //brace so do nothing
            break;
        case 1:strCpy(Sender,next);
            break;
        case 2:strCpy(Recipient,next);
            break;
        case 3:strCpy(Command,next);
            break;
        default:
            if(strCmp(next,"}"))
                return;
            strCpy(Other[i-4],next); //this make sense,(i guess)!!!!!!!!!!!!!
            otherUsed++;
            // why is this i-4....?
            break;
        }
    }
}

void Packet::CamCoords(char Sendme[])
{
    strCpy(Sendme, "{ Cam Con Location ");
}

void Packet::BuildErrorPacket(char msg[])
{
    strCpy(Command,msg);
    strCpy(Recipient,"Con");
    strCpy(Sender,"?");

}
