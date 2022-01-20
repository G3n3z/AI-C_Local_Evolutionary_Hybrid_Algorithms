#include "utils.h"
#include "string.h"

void leFicheiro(char *nome_fich, int *vert, int *arestas) {
    FILE *f;

    f=fopen(nome_fich, "r");
    if(f==NULL)
    {
        printf("Erro no acesso ao ficheiro dos dados\n");
        exit(1);
    }
    char linha[100];
    while(fscanf(f, "%[^\n] ", linha) != EOF && linha[0] != 'p'){}
    sscanf(linha, "%*s %*s %d %d", vert, arestas);

    fclose(f);
}

void init_rand(){
    srand((unsigned)time(NULL));
}

int random_l_h(int min, int max)
{
    return min + rand() % (max-min+1);
}

void preencheMatriz_ini(int arestas, int *matriz_ini, FILE* f) {

    char linha[100];
    int i = 0;
    while(fscanf(f, "%[^\n] ", linha) != EOF && i < (arestas*2)){
        sscanf(linha, "%*c %d %d", matriz_ini+i, matriz_ini+i+1);
        i+=2;
    }
}

void gera_sol_inicial(int *sol, int v) {
    int i, x;

    for(i=0; i<v; i++)
        sol[i]=0;
    for(i=0; i<(v/2); i++)
    {
        do
            x = random_l_h(0, v-1);
        while(sol[x] != 0);
        sol[x]=1;
    }
}

int availa_solucao(int *sol, int *matriz, int vert, int arestas){
    int i, j, k=0;
    //precorrer sol e para cada valor

    for(i=0;i<vert;i++){
        if(*(sol+i) == 1){ // para avaliara so os que estao a 1
            for(j=0;j < arestas*2 ; j+=2){ // percorre matriz
                //printf("%d \n", *(matriz+j));
                if(*(matriz+j) > i+1)  //Serve para nao processar dados desnecesários
                   break;
               if(*(matriz+j) == i+1){ //Quando encontramos um nó do la do esquerdo da tabela com um valor da solucao
                   k=0;
                   while (k<vert){
                       if(*(matriz+j+1) == k+1 && *(sol+k) == 1){
                           return 0;
                       }
                       ++k;
                   }
               }
            }
        }
    }

    return 1;
}

void escreve_sol(int *sol, int vert)
{
    int i;

    printf("\nSolucao: ");
    for(i=0; i<vert; i++)
        if(sol[i]==1)
            printf("%2d  ", i+1);
    printf("\n");
}

void substitui(int a[], int b[], int n)
{
    int i;
    for(i=0; i<n; i++)
        a[i]=b[i];
}



int availa_solucao_int(int *sol, int *matriz, int vert, int arestas){
    int i, j, k=0, r;
    //precorrer sol e para cada valor

    for(i=0;i<vert;i++){
        if(*(sol+i) == 1){ // para avaliara so os que estao a 1
            for(j=0;j < arestas*2 ; j+=2){ // percorre matriz
                //printf("%d \n", *(matriz+j));
                if(*(matriz+j) > i+1)  //Serve para nao processar dados desnecesários
                    break;
                if(*(matriz+j) == i+1){ //Quando encontramos um nó do la do esquerdo da tabela com um valor da solucao
                    k=0;
                    if(*(sol+(*(matriz + j+ 1)-1))== 1){
                        r=random_l_h(0,1);
                        r==0? (*(sol+(*(matriz+j)-1)) = 0) : (*(sol+(*(matriz + j+ 1)-1)) = 0);
                    }
                }
            }
        }
    }

    return 1;
}


void leOpcoes(int* op1, int *op2){

    char c[10];

    do {
        printf("\n\n1 - Vizinhanca 1\n2 - Vizinhanca 2\n");
        printf("Digite a sua opcao: ");
        fgets(c, sizeof(c) - 1, stdin);
        c[strlen(c) - 1] = '\0';
    } while (strlen(c) != 1 || (atoi(c) <= 0 || atoi(c) > 2));

    *op1 = atoi(c);

    do {
        printf("\n\n1 - Reparacao Imediata\n2 - Reparacao aleatoria\n");
        printf("Digite a sua opcao: ");
        fgets(c, sizeof(c) - 1, stdin);
        c[strlen(c) - 1] = '\0';
    } while (strlen(c) != 1 || (atoi(c) <= 0 || atoi(c) > 2));

    *op2 = atoi(c);

}