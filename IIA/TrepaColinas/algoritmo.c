#include "algoritmo.h"
#include <math.h>

float rand_01()
{
    return ((float)rand())/RAND_MAX;
}

int trepa_colinas(int sol[], int *mat, int vert, int arestas, int num_iter, int op, int op2)
{
    int *nova_sol, custo, custo_viz, i;
    int rep;
    nova_sol = malloc(sizeof(int)*vert);
    if(nova_sol == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
    // Avalia solucao inicial
    if(op2 ==1)
        custo = calcula_fit1(sol, mat, vert, arestas, &rep);
    else
        custo = calcula_fit(nova_sol, mat, vert, arestas);
    for(i=0; i<num_iter; i++)
    {
        // Gera vizinho
        op==1?(gera_vizinho1(sol, nova_sol, vert)) : gera_vizinho2(sol, nova_sol, vert);
        // Avalia vizinho
        if(op2 == 1)
            custo_viz = calcula_fit1(nova_sol, mat, vert, arestas, &rep);
        else
            custo_viz = calcula_fit(nova_sol, mat, vert, arestas);
        // Aceita vizinho se o custo diminuir (problema de minimizacao)
        if(custo_viz > custo)
        {
            substitui(sol, nova_sol, vert);
            custo = custo_viz;
        }
    }
    free(nova_sol);
    return custo;
}





int calcula_fit1(int sol[], int *mat, int vert, int arestas, int *rep)
{
    int total=0;
    *rep = -1;
    int i;

    availa_solucao_int(sol,mat, vert, arestas);
    for(i=0; i<vert; i++){
        if(sol[i]==1){
            ++total;
        }
    }
    return total;
}

int calcula_fit(int sol[], int *mat, int vert, int arestas)
{
    int total=0;

    int i;

    while(!availa_solucao(sol,mat, vert, arestas)){
        repara_solucao(sol, vert);
    }
    for(i=0; i<vert; i++){
        if(sol[i]==1){
            ++total;
        }
    }
    return total;
}

void repara_solucao(int sol[], int vert){
    int p;
    do {
        p = random_l_h(0, vert-1);
    }while(sol[p] == 0);

    sol[p] = 0;
}


void gera_vizinho1(int a[], int b[], int n)
{
    int i, p1;

    for(i=0; i<n; i++)
        b[i]=a[i];
    // Encontra posicao com valor 0
    do
        p1=random_l_h(0, n-1);
    while(b[p1] != 0);

    b[p1] = 1;

}

void repara_solucao_int(int sol[], int *vert){

    sol[*vert] = 0;

}


void gera_vizinho2(int a[], int b[], int n)
{
    int i, p1, p2, p3;

    for(i=0; i<n; i++)
        b[i]=a[i];
    // Encontra posicao com valor 0

    do
        p2=random_l_h(0, n-1);
    while(b[p2] == 0);


    do
        p1=random_l_h(0, n-1);
    while(b[p1] != 0);


    do
        p3=random_l_h(0, n-1);
    while(b[p3] != 0);

    b[p1] = 1;
    b[p2] = 0;
    b[p3] = 1;

}

