#ifndef TREPACOLINAS_UTILS_H
#define TREPACOLINAS_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void leFicheiro(char *nome_fich, int *vertices, int *arestas);
void init_rand(void);
int random_l_h(int min, int max);
void preencheMatriz_ini(int arestas, int *matriz_ini, FILE* f);
void gera_sol_inicial(int *sol, int v);
void escreve_sol(int *sol, int vert);
int availa_solucao(int *s, int *matriz, int vert, int arestas);
void substitui(int a[], int b[], int n);
int availa_solucao_int(int *sol, int *matriz, int vert, int arestas);
void leOpcoes(int* op1, int * op2);

#endif //TREPACOLINAS_UTILS_H
