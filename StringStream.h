#ifndef STRINGSTREAM_H
#define STRINGSTREAM_H
#include "Cstring.h"

class StringStream
{
public:
    StringStream(){}
    StringStream(char* s);

    ~StringStream();
    StringStream(const StringStream& s);
    StringStream& operator=(const StringStream& other);

    char* getStr();
    bool endOfStr();
    void getNext(char out[]);
    int getSize();

private:
    char* str;
    int pos;

    void isSpace();
};

#endif // STRINGSTREAM_H
