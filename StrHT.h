#ifndef STRHT_H
#define STRHT_H
// Index integers using strings

#define NOT_PRESENT -1
typedef struct _strHT* StrHT;

StrHT newStrHT(int size);

int getPop(StrHT t);

char *getStr(StrHT t, char *str);   // get an addressable pointer to an identical string - NULL if not in table
void  addVal(StrHT t, char *str, int val);
int   getVal(StrHT t, char *str);       // NOT_PRESENT is returned if not present
void  delVal(StrHT t, char *str);

void destroyStrHT(StrHT t);

#endif