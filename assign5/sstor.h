struct sstor {
    int sz;
    int maxsz;
    char item[1];
};

#define INITSZ 100 
#define INCRSZ 100
#define SSTORSZ(n) ((size_t)(sizeof(struct sstor) + ((n)-1)*sizeof(char)))

struct sstor *init_sstor(int num);
int ins_sstor(char *data, struct sstor **p);
void prt_sstor(int num);
void debug_sstor(struct sstor *p);
