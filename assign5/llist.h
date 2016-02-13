struct llist {
    struct lnode *head;
    struct lnode *tail;
    struct sstor *strings;
};

struct lnode {
    int item;
    struct lnode *next;
    struct lnode *prev;
};

struct llist *init_llist(void);
void prt_llist(struct llist *ll);
void free_llist(struct llist *ll);
struct lnode *ins_llist(char *data, struct llist *ll);
//int del_llist(int data, struct llist *ll);
int valid_llist(struct llist *ll);
int del_llist(struct llist *ll, int num);
