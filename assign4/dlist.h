struct dlist
{
    int size;
    int maxSize;
    char item[1][1024];
};

#define INITSIZE 6
#define INCRSIZE 9
#define DLISTSIZE(n) ((size_t)(sizeof(struct dlist) + (n*1024)))

struct dlist *initDlist(int num);
int insDlist(char data[], struct dlist **p);
int delDlist(struct dlist *p, int num);
void printDlist(struct dlist *p);
int stringCmp(const void *a, const void *b);
