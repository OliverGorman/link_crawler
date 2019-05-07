// Index integers using strings
typedef struct _strHT* StrHT;

StrHT newStrHT(int size);

void  addVal(StrHT table, char *str, int val);
int   getVal(StrHT table, char *str);
void  delVal(StrHT table, char *str);

void destroyStrHT(StrHT table);