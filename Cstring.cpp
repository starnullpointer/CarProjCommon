#include "Cstring.h"

bool isDigit(char c)
{
    if(c>='0' && c<='9')
        return true;
    return false;
}

bool isLetter(char c)
{
    if((c>='a' && c<='z') || (c>='A' && c<='Z'))
        return true;
    return false;
}

bool isSpace(char c) //maybe don't need
{
    if(c==' ')
        return true;
    return false;
}

int charToInt(char c)
{
    int num=0;
    if(isDigit(c))
        num=c-'0';
    return num;
}

unsigned int strLen(const char *s)
{
    int i;
    for(i=0;*s!='\0';i++,s++);
    return i;
}

void append(char* d, const char* s)
{
    char* dWalk=d+strLen(d);
    for(;*s!='\0';dWalk++,s++)
        *dWalk=*s;
    *dWalk='\0';
}

void append(char* d, const char* s, int len)
{
    char* dWalk=d+strLen(d);
    for(int i=0;*s!='\0' && i<len;dWalk++,s++,i++)
        *dWalk=*s;
    *dWalk='\0';
}

void strCpy(char* d,const char* s)
{
    for(;*s!='\0';d++,s++)
        *d=*s;
    *d='\0';
}

void strCpy(char* d, const char *s, int len)
{
    for(int i=0;*s!='\0' && i<len;d++,s++,i++)
        *d=*s;
    *d='\0';
}

bool strCmp(const char* one, const char* two)
{
    const char* walk1=one;
    const char* walk2=two;
    while(*walk1!='\0' && *walk2!='\0'){
        if(*walk1!=*walk2)
            return false;
        walk1++;walk2++;
    }
    if(strLen(one)!=strLen(two))
        return false;
    return true;
}

void getWordFromString(int start, int end, char word[], char src[]){
    int i;
    for (i = 0; i < end -start; i++){
        word[i] = src[i+start];
    }
    word[i] = '\0';


}



