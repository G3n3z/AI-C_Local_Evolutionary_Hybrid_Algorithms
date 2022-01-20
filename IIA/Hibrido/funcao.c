//
// Created by Daniel Fernandes on 04/01/2022.
//
#include "stdio.h"
#include "stdlib.h"
#include "algoritmo.h"
#include "funcao.h"
#include "utils.h"
#define PROBGERAVIZ 1
#define GENERATIONS_TC 10000
float eval_individual_reparado3(int sol[], struct info d, int mat[][2], int *v)
{
    int     i;
    int    total = 0;

    availa_solucao_int(sol,mat, d.vertices, d.arestas);
    for(i=0; i<d.vertices; i++){
        if(sol[i]==1){
            ++total;

        }

    }
    *v = 1;
    return total;
}





void evaluate(pchrom pop, struct info d, int mat[][2])
{
    int i;

    for (i=0; i<d.popsize; i++){
        pop[i].fitness = eval_individual_reparado3(pop[i].p, d, mat, &pop[i].valido);

    }

}

void trepa_colinas(pchrom pop, struct info d, int mat[][2]){

    int i, j;
    chrom vizinho;

    for ( i = 0; i < d.popsize; ++i) {
        for (j = 0; j < GENERATIONS_TC; j++) {
            if (rand_01() < PROBGERAVIZ){
                gera_vizinho1(pop[i].p, vizinho.p, d.vertices);
                vizinho.fitness = eval_individual_reparado3(vizinho.p, d, mat, &vizinho.valido);
                if(vizinho.fitness >= pop[i].fitness)
                    pop[i] = vizinho;
            }
        }
    }
}

void substitui(int a[], int b[], int n)
{
    int i;
    for(i=0; i<n; i++)
        a[i]=b[i];
}




int calcula_fit(int sol[], int mat[][2], int vert, int arestas)
{
    int total=0;
    int i;


    availa_solucao_int(sol, mat, vert, arestas);
    for(i=0; i<vert; i++){
        if(sol[i]==1){
            ++total;
        }
    }
    return total;
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
    while(b[p1] == 1);


    do
        p3=random_l_h(0, n-1);
    while(b[p3] == 1);

    b[p1] = 1;
    b[p2] = 0;
    b[p3] = 1;

}


