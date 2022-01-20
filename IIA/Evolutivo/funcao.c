//
// Created by Daniel Fernandes on 04/01/2022.
//

#include "algoritmo.h"
#include "funcao.h"
#include "utils.h"


float eval_individual_reparado3(int sol[], struct info d, int mat[][2], int *v)
{
    int     i;
    int    total = 0;

    if(availa_solucao_int(sol,mat, d.vertices, d.arestas)){
        for(i=0; i<d.vertices; i++){
            if(sol[i]==1){
                ++total;

            }
            *v = 1;
        }
    }
    else{
        *v = 0;
    }

    return total;
}

float eval_individual_reparado_aleatorio(int sol[], struct info d, int mat[][2], int *v){
    int total=0;

    int i;

    while(!availa_solucao(sol,mat, d.vertices, d.arestas)){
        repara_solucao(sol, d.vertices);
    }
    for(i=0; i<d.vertices; i++){
        if(sol[i]==1){
            ++total;
        }
    }
    *v = 1;
    return total;
}

void repara_solucao(int sol[], int vert){
    int p;
    do {
        p = random_l_h(0, vert-1);
    }while(sol[p] == 0);

    sol[p] = 0;
}

void evaluate(pchrom pop, struct info d, int mat[][2])
{
    int i;

    for (i=0; i<d.popsize; i++)
        pop[i].fitness = eval_individual_reparado3(pop[i].p, d, mat, &pop[i].valido);
        //pop[i].fitness = eval_individual_reparado_aleatorio(pop[i].p, d, mat, &pop[i].valido);
}


