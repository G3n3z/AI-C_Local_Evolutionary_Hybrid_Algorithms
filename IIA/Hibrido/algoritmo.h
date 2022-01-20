#define MAX_OBJ 500		// Numero maximo de objectos

// EStrutura para armazenar parametros
struct info
{
    // Tamanho da popula��o
    int     popsize;
    // Probabilidade de muta��o
    float   pm;
    // Probabilidade de recombina��o
    float   pr;
    // Tamanho do torneio para sele��o do pai da pr�xima gera��o
    int     tsize;
    // Constante para avalia��o com penaliza��o
    float   ro;
    // N�mero de ligacoes maximas
    int     arestas;
    // Numero de vertices
    int     vertices;
    // N�mero de gera��es
    int     numGenerations;
};

// Individuo (solu��o)
typedef struct individual chrom, *pchrom;

struct individual
{
    // Solu��o (objetos que est�o dentro da mochila)
    int     p[MAX_OBJ];
    // Valor da qualidade da solu��o
    float   fitness;
    // 1 se for uma solu��o v�lida e 0 se n�o for
    int     valido;
};

void tournament(pchrom pop, struct info d, pchrom parents);

void genetic_operators(pchrom parents, struct info d, pchrom offspring, int op1, int op2);

void crossover(pchrom parents, struct info d, pchrom offspring);

void mutation(pchrom offspring,struct info d);

void mutationInversao(pchrom offspring, struct info d);
void crossover2points(pchrom parents, struct info d, pchrom offspring);
