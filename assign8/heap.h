#define PARENT(r, n) (0 < (r) && (r) < (n) ? ((r)-1)/2 : -1)
#define LEFT(r, n) (2*(r)+1 < (n) ? 2*(r)+1 : -1)
#define RIGHT(r, n) (2*(r)+2 < (n) ? 2*(r)+2 : -1)
#define INITHSZ 2
#define INCRHSZ 1
#define DLISTSZ(n) ((size_t)(sizeof(struct heap) + ((n)-1)*sizeof(int)))

struct heap
{
	int sz;
	int maxsz;
	int item[1];
};

void print_heap(struct heap *, int);
void build_heap(struct heap *, int);
void siftdown(struct heap *, int, int);
void siftup(struct heap *, int, int);
void insert_heap(struct heap **, int);
int valid_heap(struct heap *, int);
int rmmin_heap(struct heap *, int *);
struct heap *init_dlist(int num);
int ins_dlist(int data, struct heap **p);
