#include "StringStream.h"

StringStream::StringStream(char* s)
{
    str = new char[100];
    strCpy(str, s);
    pos = 0;
}

StringStream::~StringStream()
{
    delete [] str;
}

StringStream::StringStream(const StringStream& s)
{
    str=new char[100];
    strCpy(str,s.str);
}

StringStream& StringStream::operator=(const StringStream& other)
{
    // uhh...... does delete need []....? - Mac
    if(this!=&other){
        delete [] str;
        str=new char[100];
        strCpy(str,other.str);
    }
    return *this;
}

// ahem.... super dangereous..... --Mac
char* StringStream::getStr()
{
    return str;
}

bool StringStream::endOfStr()
{
    if(pos >= getSize()){
        return true;
    }
    else{
        return false;
    }

}

int StringStream::getSize(){
    char* sWalk = str;
    int count = 0;
    while(*sWalk != '\0'){
        sWalk++;
        count++;
    }
    return count;
}

void StringStream::getNext(char out[])
{
    //skip spaces:
    while(str[pos]==' ' && str[pos] !='\0'){
        pos++;
    }
    int hold = pos;
    while(str[pos]!=' ' && str[pos]!='\0'){
        pos++;
    }
    //pos is at the end of token. either space or null
//    int end = pos+last_out;
    getWordFromString(hold, pos,out, str);


}

void StringStream::isSpace()
{
    if(*str==' '){

    }
}









