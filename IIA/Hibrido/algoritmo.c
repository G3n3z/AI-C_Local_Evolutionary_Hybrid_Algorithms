//
// Created by Daniel Fernandes on 04/01/2022.
//
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "algoritmo.h"
#include "utils.h"

// Preenche uma estrutura com os progenitores da pr�xima geracao, de acordo com o resultados do torneio binario (tamanho de torneio: 2)
// Parametros de entrada: populacao actual (pop), estrutura com parametros (d) e populacao de pais a encher
void tournament(pchrom pop, struct info d, pchrom parents)
{
    int i, x1, x2;

    // Realiza popsize torneios
    for(i=0; i<d.popsize;i++)
    {
        x1 = random_l_h(0, d.popsize-1);
        do
            x2 = random_l_h(0, d.popsize-1);
        while(x1==x2);
        if(pop[x1].fitness > pop[x2].fitness)		// Problema de maximizacao
            parents[i]=pop[x1];
        else
            parents[i]=pop[x2];
    }
}

// Operadores geneticos a usar na gera��o dos filhos
// Par�metros de entrada: estrutura com os pais (parents), estrutura com par�metros (d), estrutura que guardar� os descendentes (offspring)
void genetic_operators(pchrom parents, struct info d, pchrom offspring, int op1, int op2)
{
    if(op1==1)
        // Recombina��o com um ponto de corte
        crossover(parents, d, offspring);
    else
        crossover2points(parents, d, offspring);
    if (op2==1)
        // Muta��o bin�ria
        mutation(offspring, d);
    else
        mutationInversao(offspring, d);
}

// Preenche o vector descendentes com o resultado das opera��es de recombina��o
// Par�metros de entrada: estrutura com os pais (parents), estrutura com par�metros (d), estrutura que guardar� os descendentes (offspring)
void crossover(pchrom parents, struct info d, pchrom offspring)
{
    int i, j, point;

    for (i=0; i<d.popsize; i+=2)
    {
        if (rand_01() < d.pr)
        {
            point = random_l_h(0, d.vertices-1);
            for (j=0; j<point; j++)
            {
                offspring[i].p[j] = parents[i].p[j];
                offspring[i+1].p[j] = parents[i+1].p[j];
            }
            for (j=point; j<d.vertices; j++)
            {
                offspring[i].p[j]= parents[i+1].p[j];
                offspring[i+1].p[j] = parents[i].p[j];
            }
        }
        else
        {
            offspring[i] = parents[i];
            offspring[i+1] = parents[i+1];
        }

    }
}

void crossover2points(pchrom parents, struct info d, pchrom offspring)
{
    int i, j, point1, point2;

    for (i=0; i<d.popsize; i+=2)
    {
        if (rand_01() < d.pr)
        {
            point1 = random_l_h(0, d.vertices-1);
            do {
                point2 = random_l_h(0, d.vertices - 1);

            }while (point1 == point2);

            int temp;
            temp = point1 < point2 ? point1 : point2;
            if(temp != point1){ //Se o point 1 for maior, temp tem o valor de point2
                point2 = point1;
                point1 = temp;
            }

            for (j=0; j<point1; j++)
            {
                offspring[i].p[j] = parents[i].p[j];
                offspring[i+1].p[j] = parents[i+1].p[j];
            }
            for (j=point1; j<point2; j++)
            {
                offspring[i].p[j]= parents[i+1].p[j];
                offspring[i+1].p[j] = parents[i].p[j];
            }
            for (j=point2; j<d.vertices; j++)
            {
                offspring[i].p[j]= parents[i].p[j];
                offspring[i+1].p[j] = parents[i+1].p[j];
            }
        }
        else
        {
            offspring[i] = parents[i];
            offspring[i+1] = parents[i+1];
        }
    }
}


// Muta��o bin�ria com v�rios pontos de muta��o
// Par�metros de entrada: estrutura com os descendentes (offspring) e estrutura com par�metros (d)
void mutation(pchrom offspring, struct info d)
{
    int i, j;

    for (i=0; i<d.popsize; i++){
        for (j=0; j<d.vertices; j++){
            if (rand_01() < d.pm)
                offspring[i].p[j] = !(offspring[i].p[j]);
        }

    }
}


void mutationInversao(pchrom offspring, struct info d) {
    int i, j, temp;

    for (i = 0; i < d.popsize; i++){
        for (j = 0; j < d.vertices; j++)
            if (rand_01() < d.pm) {
                temp = offspring[i].p[j];
                offspring[i].p[j] = offspring[i].p[j + 1];
                offspring[i].p[j + 1] = temp;
                j++;
            }

    }
}