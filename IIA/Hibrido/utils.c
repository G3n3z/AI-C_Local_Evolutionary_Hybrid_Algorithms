//
// Created by Daniel Fernandes on 04/01/2022.
//


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "algoritmo.h"
#include "utils.h"
#define DEFAULTPOPSIZE 100
#define DEFAULTPM 0.01
#define DEFAULTPR 0.7
#define DEFAULTAMSIZE 2
#define DEFAULTNUMGEN 2500



// Inicializa��o do gerador de n�meros aleat�rios
void init_rand()
{
    srand((unsigned)time(NULL));
}

// Leitura dos par�metros e dos dados do problema
// Par�metros de entrada: Nome do ficheiro e matriz a preencher com os dados dos objectos (peso e valor)
// Par�metros de sa�da: Devolve a estrutura com os par�metros
struct info init_data(char *filename)
{
    struct  info x;
    FILE    *f;
    int     i;

    f = fopen(filename, "r");
    if (!f)
    {
        printf("File not found\n");
        exit(1);
    }
    // Leitura dos par�metros do problema
    //fscanf(f, " pop: %d", &x.popsize);
    //fscanf(f, " pm: %f", &x.pm);
    //fscanf(f, " pr: %f", &x.pr);
    //fscanf(f, " tsize: %d", &x.tsize);
    //fscanf(f, " max_gen: %d", &x.numGenerations);

    x.popsize = DEFAULTPOPSIZE;
    x.pm = DEFAULTPM;
    x.pr = DEFAULTPR;
    x.tsize = DEFAULTAMSIZE;
    x.numGenerations = DEFAULTNUMGEN;

    char linha[100];
    while(fscanf(f, "%[^\n] ", linha) != EOF && linha[0] != 'p'){}
    sscanf(linha, "%*s %*s %d %d", &x.vertices, &x.arestas);



    if (x.vertices > MAX_OBJ)
    {
        printf("Number of vertices is superior to MAX_OBJ\n");
        exit(1);
    }
    x.ro = 0.0;


    i = 0;
    /*
    while(fscanf(f, "%[^\n] ", linha) != EOF && i < x.arestas){
        sscanf(linha, "%*c %d %d", &mat[i][0], &mat[i][1]);
        ++i;
    }
     */
    return x;
}
int *init_matriz(char fich[100], int *pInt, int arestas) {
    FILE    *f;
    int     i;

    f = fopen(fich, "r");
    if (!f)
    {
        printf("File not found\n");
        exit(1);
    }
    char linha[100];
    while(fscanf(f, "%[^\n] ", linha) != EOF && linha[0] != 'p'){}

    pInt = malloc(sizeof(int)*arestas*2);
    if(pInt == NULL)
        exit(1);

    i=0;
    while(fscanf(f, "%[^\n] ", linha) != EOF && i < arestas*2){
        sscanf(linha, "%*c %d %d", pInt + i, pInt + i+1);
        i+=2;
    }

    return pInt;


}



// Simula o lan�amento de uma moeda, retornando o valor 0 ou 1
int flip()
{
    if ((((float)rand()) / RAND_MAX) < 0.5)
        return 0;
    else
        return 1;
}

// Criacao da populacao inicial. O vector e alocado dinamicamente
// Par�metro de entrada: Estrutura com par�metros do problema
// Par�metro de sa�da: Preenche da estrutura da popula��o apenas o vector bin�rio com os elementos que est�o dentro ou fora da mochila
pchrom init_pop(struct info d)
{
    int     i, j;
    pchrom  indiv;

    indiv = malloc(sizeof(chrom)*d.popsize);
    if (indiv==NULL)
    {
        printf("Erro na alocacao de memoria\n");
        exit(1);
    }
    for (i=0; i<d.popsize; i++)
    {
        for (j=0; j<d.vertices; j++)
            indiv[i].p[j] = flip();
    }
    return indiv;
}

// Actualiza a melhor solu��o encontrada
// Par�metro de entrada: populacao actual (pop), estrutura com par�metros (d) e a melhor solucao encontrada at� a gera��oo imediatamente anterior (best)
// Par�metro de sa�da: a melhor solucao encontrada at� a gera��o actual
chrom get_best(pchrom pop, struct info d, chrom best)
{
    int i;

    for (i=0; i<d.popsize; i++)
    {
        if (best.fitness < pop[i].fitness)
            best=pop[i];
    }
    return best;
}

// Devolve um valor inteiro distribuido uniformemente entre min e max
int random_l_h(int min, int max)
{
    return min + rand() % (max-min+1);
}

// Devolve um valor real distribuido uniformemente entre 0 e 1
float rand_01()
{
    return ((float)rand())/RAND_MAX;
}

// Escreve uma solu��o na consola
// Par�metro de entrada: populacao actual (pop) e estrutura com par�metros (d)
void write_best(chrom x, struct info d)
{
    int i;

    printf("\nBest individual: %4.1f\n", x.fitness);
    for (i=0; i<d.vertices; i++)
        printf("%d", x.p[i]);
    putchar('\n');

    printf("Solucao: \n");
    for (i=0; i<d.vertices; i++)
        if(x.p[i] == 1)
            printf("%d ", i+1);
}



struct info askMudaParametros(struct info x, int *op1, int *op2){

    int n = 0;
    char c[10];

    do {


        printf("\nPretende alterar algum valor? \n");

        printf("1 - Populacao %d \n2 - Percentagem de mutacao %f\n", x.popsize, x.pm);
        printf("3 - Percentagem de recombinacao %f\n", x.pr);
        printf("4 - Tsize: %d\n", x.tsize);
        printf("5 - Maximo de gen %d\n", x.numGenerations);
        printf("6 - Comecar\n");


        do {
            printf("Digite a sua opcao: ");
            fgets(c, sizeof(c) - 1, stdin);
            c[strlen(c) - 1] = '\0';
        } while (strlen(c) != 1 || (atoi(c) <= 0 || atoi(c) > 6));


         n = atoi(c);
        float qtd;

        if (n == 6)
            break;


        printf("Digite a qtd prentendida: ");
        scanf("%f", &qtd);

        switch (n) {
            case 1:
                x.popsize = (int) qtd;
                printf("Valor de populacao alterado para %d\n", x.popsize);
                break;
            case 2:
                x.pm = qtd;
                printf("Valor de Percentagem de mutacao alterado para %f\n", x.pm);
                break;
            case 3:
                x.pr = qtd;
                printf("Valor de Percentagem de recombinacao para %f\n", x.pr);
                break;
            case 4:
                x.tsize = (int) qtd;
                printf("Valor de tsize alterado para %d\n", x.tsize);
                break;
            case 5:
                x.numGenerations = (int) qtd;
                printf("Valor de Maximo de gen alterado para %d\n", x.numGenerations);
                break;

        }

    } while (n!=6);



    do {
        printf("\n\nTipo de Recombinacao: ");
        printf("\n1 - Recombinacao de 1 corte de ponto\n2 - Recombinacao de 2 corte de ponto\n");
        printf("Digite a sua opcao: ");
        fgets(c, sizeof(c) - 1, stdin);
        c[strlen(c) - 1] = '\0';
    } while (strlen(c) != 1 || (atoi(c) <= 0 || atoi(c) > 2));

    *op1 = atoi(c);


    do {
        printf("\n\nTipo de Mutacao: ");
        printf("\n1 - Mutacao Binaria\n2 - Mutacao de Inversao\n");
        printf("Digite a sua opcao: ");
        fgets(c, sizeof(c) - 1, stdin);
        c[strlen(c) - 1] = '\0';
    } while (strlen(c) != 1 || (atoi(c) <= 0 || atoi(c) > 2));

    *op2 = atoi(c);


    return x;


}


int availa_solucao(int *sol, int matriz[][2], int vert, int arestas){
    int i, j, k=0;
    //precorrer sol e para cada valor

    for(i=0;i<vert;i++){
        if(*(sol+i) == 1){ // para avaliara so os que estao a 1
            for(j=0;j < arestas ; j++){ // percorre matriz
                //printf("%d \n", *(matriz+j));
                if(matriz[j][0] > i+1)  //Serve para nao processar dados desnecesários
                    break;
                if(matriz[j][0] == i+1){ //Quando encontramos um nó do la do esquerdo da tabela com um valor da solucao
                    k=0;
                    while (k<vert){
                        if(matriz[j][1] == k+1 && *(sol+k) == 1){
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


int availa_solucao_int(int *sol, int matriz[][2], int vert, int arestas){
    int i, j, k=0, r;
    //precorrer sol e para cada valor
    j=0;
    for(i=0;i<vert;i++){
        if(*(sol+i) == 1){ // para avaliara so os que estao a 1
            for(;j < arestas ; j++){ // percorre matriz
                //printf("%d \n", *(matriz+j));
                if(matriz[j][0] > i+1)  //Serve para nao processar dados desnecesários
                    break;
                if(matriz[j][0] == i+1){ //Quando encontramos um nó do lado esquerdo da tabela com um valor da solucao
                    k=0;
                    if(*(sol+matriz[j][1]-1) == 1){
                        r=random_l_h(0,1);
                        r==0? (*(sol+matriz[j][0]-1) = 0) : (*(sol+(matriz[j][1]-1)) = 0);

                    }

                }
            }
        }
    }
    return 1;
}
