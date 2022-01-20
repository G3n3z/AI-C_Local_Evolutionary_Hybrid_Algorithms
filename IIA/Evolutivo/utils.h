struct info init_data(char *s);

pchrom init_pop(struct info d);

chrom get_best(pchrom pop, struct info d, chrom best);

void write_best(chrom x, struct info d);

void init_rand();

int random_l_h(int min, int max);

float rand_01();

int flip();

struct info askMudaParametros(struct info x, int *op1, int *op2);
int availa_solucao(int *sol, int matriz[][2], int vert, int arestas);
int availa_solucao_int(int *sol, int matriz[][2], int vert, int arestas);




int *init_matriz(char fich[100], int *pInt, int arestas);