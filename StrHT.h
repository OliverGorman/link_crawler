// Index integers using strings
typedef struct _strHT* StrHT;

StrHT newStrHT(int size);

int getPop(StrHT t);

void  addVal(StrHT t, char *str, int val);
int   getVal(StrHT t, char *str);       // -1 is returned if not present
void  delVal(StrHT t, char *str);

void destroyStrHT(StrHT t);
