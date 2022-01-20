void evaluate(pchrom pop, struct info d, int mat[][2]);

float eval_individual_reparado3(int sol[], struct info d, int mat[][2], int *v);
void gera_vizinho1(int a[], int b[], int n);
void gera_vizinho2(int a[], int b[], int n);
int calcula_fit(int sol[], int mat[][2], int vert, int arestas);
void substitui(int a[], int b[], int n);
void trepa_colinas(pchrom pop, struct info d, int mat[][2]);