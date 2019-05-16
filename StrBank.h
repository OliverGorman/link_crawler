// Takes a string and returns an addressable pointer to an identical string
// This pointer will persist until delStr is called
// Saves you mallocing identical strings
// Uses a hash table
typedef struct _strBank* StrBank;

StrBank newStrBank(int size);

int getSBSize(StrBank b);

void  addStr(StrBank bank, char *str);
char* getStr(StrBank bank, char *str);
void  delStr(StrBank bank, char *str);

void destroyStrBank(StrBank bank);
