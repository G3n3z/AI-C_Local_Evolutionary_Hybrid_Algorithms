#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoritmo.h"

#define DEFAULT_RUNS 30
#define DEFAULT_ITERATIONS 100

int main(int argc, char *argv[]) {

    char    nome_fich[100];
    float   mbf = 0.0;
    int      *sol, *best;
    int     vert, arestas, num_iter, k, runs, best_vert=0, num_vert;
    FILE    *f;

    if(argc == 4){
        num_iter = atoi(argv[3]);
        runs = atoi(argv[2]);
        strcpy(nome_fich, argv[1]);
    }
    else
        if(argc == 3)
        {
            num_iter = DEFAULT_ITERATIONS;
            runs = atoi(argv[2]);
            strcpy(nome_fich, argv[1]);
        }
        else{
            if(argc == 2)
            {
                num_iter = DEFAULT_ITERATIONS;
                runs = DEFAULT_RUNS;
                strcpy(nome_fich, argv[1]);
            }
            else
            {
                num_iter = DEFAULT_ITERATIONS;
                runs = DEFAULT_RUNS;
                printf("Nome do Ficheiro: ");
                fgets(nome_fich,sizeof(nome_fich)-1, stdin);
                nome_fich[strlen(nome_fich)-1] = '\0';
            }
        }
    if(runs <= 0)
        return 0;
    init_rand();

    //leFicheiro(nome_fich, &vert, &arestas);
    f=fopen(nome_fich, "r");
    if(f==NULL)
    {
        printf("Erro no acesso ao ficheiro dos dados\n");
        exit(1);
    }
    char linha[100];
    while(fscanf(f, "%[^\n] ", linha) != EOF && linha[0] != 'p'){}
    sscanf(linha, "%*s %*s %d %d", &vert, &arestas);
    if(vert >= 500){
        printf("Apenas e permitido instancias com numero de vertices inferior a 500\n");
        fclose(f);
        exit(1);
    }

    int *matriz_ini;
    matriz_ini = malloc(sizeof(int)*(arestas*2));
    if(matriz_ini == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
    preencheMatriz_ini(arestas, matriz_ini, f);

    sol = malloc(sizeof(int)*vert);
    best = malloc(sizeof(int)*vert);
    if(sol == NULL || best == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }

    int op1=0;
    int op2;
    leOpcoes(&op1, &op2);

    for(k=0; k<runs; k++){

        gera_sol_inicial(sol, vert);
        escreve_sol(sol, vert);
        num_vert = trepa_colinas(sol, matriz_ini, vert, arestas, num_iter, op1, op2);
        printf("%d\n", num_vert);printf("\nRepeticao %d:", k);
        escreve_sol(sol, vert);
        printf("Custo final: %2d\n", num_vert);
        mbf += num_vert;
        if(k==0 || best_vert < num_vert)
        {
            best_vert = num_vert;
            substitui(best, sol, vert);
        }
    }
    // Escreve resultados globais
    printf("\n\nMBF: %f\n", mbf/k);
    printf("\nMelhor solucao encontrada");
    escreve_sol(best, vert);
    printf("Custo final: %2d\n", best_vert);

    free(matriz_ini);
    free(sol);
    free(best);
    return 0;
}

