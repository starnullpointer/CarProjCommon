#ifndef CSTRING
#define CSTRING

using namespace std;

bool isDigit(char c);
bool isLetter(char c);
bool isSpace(char c);
int charToInt(char c);
unsigned int strLen(const char* s);
void append(char* d, const char* s);
void append(char* d, const char* s, int len);
void strCpy(char* d, const char *s);
void strCpy(char* d, const char *s, int len);
bool strCmp(const char* one, const char* two);

void getWordFromString(int start, int end, char word[], char src[]);


#endif // CSTRING

