#ifndef TREPACOLINAS_ALGORITMO_H
#define TREPACOLINAS_ALGORITMO_H

#include "utils.h"

int trepa_colinas(int sol[], int *mat, int vert, int arestas, int num_iter, int op, int op2);

void repara_solucao(int sol[], int vert);
void gera_vizinho1(int a[], int b[], int n);

int calcula_fit1(int sol[], int *mat, int vert, int arestas, int *rep);
int calcula_fit(int sol[], int *mat, int vert, int arestas);
void repara_solucao_int(int sol[], int *vert);

void gera_vizinho2(int a[], int b[], int n);



#endif //TREPACOLINAS_ALGORITMO_H
