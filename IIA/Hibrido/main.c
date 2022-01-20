#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoritmo.h"
#include "funcao.h"
#include "utils.h"

#define DEFAULT_RUNS	10




int main(int argc, char *argv[]) {

    char        nome_fich[100];
    struct info EA_param;
    pchrom      pop = NULL, parents = NULL;
    chrom       best_run, best_ever;
    int         gen_actual, r, runs, i, inv; // mat[500][2];
    float       mbf = 0.0;


    if(argc == 4){
        //num_iter = atoi(argv[3]);
        runs = atoi(argv[2]);
        strcpy(nome_fich, argv[1]);
    }
    else
    if(argc == 3)
    {
        //num_iter = DEFAULT_ITERATIONS;
        runs = atoi(argv[2]);
        strcpy(nome_fich, argv[1]);
    }
    else{
        if(argc == 2)
        {
            //num_iter = DEFAULT_ITERATIONS;
            runs = DEFAULT_RUNS;
            strcpy(nome_fich, argv[1]);
        }
        else
        {
            //num_iter = DEFAULT_ITERATIONS;
            runs = DEFAULT_RUNS;
            printf("Nome do Ficheiro: ");
            fgets(nome_fich,sizeof(nome_fich)-1, stdin);
            nome_fich[strlen(nome_fich)-1] = '\0';
        }
    }
    // Se o n�mero de execu��es do processo for menor ou igual a 0, termina o programa
    if (runs <= 0)
        return 0;
    //Inicializa a gera��o dos n�meros aleat�rios
    init_rand();
    int* m;
    EA_param = init_data(nome_fich);
    m = init_matriz(nome_fich, m, EA_param.arestas);

    //faz-se uma uma copia dos dados para uma variavel mais pequena de modo a otimizar a velocidade
    int mat[EA_param.arestas][2];
    for (int j = 0; j < EA_param.arestas; ++j) {
        for (int k = 0; k < 2; ++k) {

            mat[j][k] = *(m+j*2+k);
        }
    }

    free(m);

    int op1 = 0, op2 = 0;
    EA_param = askMudaParametros(EA_param, &op1, &op2);

    for (r=0; r<runs; r++)
    {
        //printf("Repeticao %d\n",r+1);
        // Gera��o da popula��o inicial
        pop = init_pop(EA_param);
        evaluate(pop, EA_param, mat);
        //trepa_colinas(pop, EA_param, mat); //Algoritmo hibrido 1
        gen_actual = 1;
        best_run = pop[0];
        best_run = get_best(pop, EA_param, best_run);
        parents = malloc(sizeof(chrom)*EA_param.popsize);
        if (parents==NULL)
        {
            printf("Erro na alocacao de memoria\n");
            exit(1);
        }
        // Ciclo de optimiza��o
        while (gen_actual <= EA_param.numGenerations)
        {
            // Torneio bin�rio para encontrar os progenitores (ficam armazenados no vector parents)
            tournament(pop, EA_param, parents);
            // Aplica os operadores gen�ticos aos pais (os descendentes ficam armazenados na estrutura pop)
            genetic_operators(parents, EA_param, pop, op1, op2);
            // Avalia a nova popula��o (a dos filhos)
            evaluate(pop, EA_param, mat);
            //trepa_colinas(pop, EA_param, mat);

            // Actualiza a melhor solu��o encontrada
            best_run = get_best(pop, EA_param, best_run);
            gen_actual++;
        }
        // Contagem das solu��es inv�lidas
        trepa_colinas(pop, EA_param, mat);  //Algoritmo hibrido 2
        for (inv=0, i=0; i<EA_param.popsize; i++)
            if (pop[i].valido == 0){
                inv++;
                write_best(pop[i], EA_param);
            }
        best_run = get_best(pop, EA_param, best_run);
        printf("\nRepeticao %d:", r+1);
        write_best(best_run, EA_param);
        printf("\nPercentagem Invalidos: %f\n", 100*(float)inv/EA_param.popsize);
        //if(availa_solucao(best_run.p, mat, EA_param.vertices, EA_param.arestas))
        //    printf("E valida!!!\n");
        //else
        //    printf("Nao e valida!!!\n");
        mbf += best_run.fitness;
        if (r==0 || best_run.fitness > best_ever.fitness)
            best_ever = best_run;
        // Liberta a mem�ria usada
        free(parents);
        free(pop);
    }
    // Escreve resultados globais
    printf("\n\nMBF: %f\n", mbf/r);
    printf("\nMelhor solucao encontrada");
    write_best(best_ever, EA_param);
    return 0;
}


