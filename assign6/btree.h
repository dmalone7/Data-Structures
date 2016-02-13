struct node {
    int item;
    struct node *left;
    struct node *right;
};

struct node *ins_tree(int data, struct node **tree);
int del_tree(int data, struct node **tree);
void prt_tree(struct node *tree);
void p_tree(struct node *t, int h);
void delete_tnode(struct node **p);
void free_tree(struct node *tree);
void tprt(struct node *tree, char *order);
void tp(struct node *t, char *order, int h);
int height(struct node *tree);
int width(struct node *tree);
void wid_hlp(struct node *t, int d, int *a);
int reverse(struct node *tree);
