struct node23
{
	double y1;
	double y2;
    struct node23 *son1;
    struct node23 *son2;
    struct node23 *son3;

	//3D point data
	int x;
	int y;
	int z;
};

void coor23(struct node23 *node, int newX, int newY, int newZ);
int init23(char *file);
void indent23(int n);
void print_tree23(struct node23 *node, int ht);
int height23(struct node23 *node);
double min23(struct node23 *node);
struct node23 *locate_min23(struct node23 *node);
double max23(struct node23 *node);
struct node23 *locate_max23(struct node23 *node);
struct node23 *avail23(void);
void free23(struct node23 *p);
int ckorder23(struct node23 *node);
int ckdepth23(struct node23 *node, int ht);
int ckndx23(struct node23 *node);
int valid23(struct node23 *node);
struct node23 *search23(int x, struct node23 *node);
struct node23 *insert23(double dis, int x, int y, int z, struct node23 **root);
struct node23 *addson(double x, int a, int b, int c, struct node23 *node, struct node23 **split, double *low);
int delete1(struct node23 *node, int x);
double distance(int x1, int x2, int y1, int y2, int z1, int z2);
