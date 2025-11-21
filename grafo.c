#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

//builder aresta
Aresta nova_aresta(int o, int d, int custo){
    Aresta a;
    a.o = o;
    a.d = d;
    a.custo = custo;
    return a;
}

//builder grafo
Grafo novo_grafo(){
    Grafo g;
    g.n_vertices = 0;
    g.n_arestas = 0;
    g.capacidade = 0;
    g.arestas = NULL;
    
    return g;
}

void inserir_arestas(Grafo *g, int o, int d, int custo){
    
    if (g->n_arestas == g->capacidade) {

        if (g->capacidade == 0)
            g->capacidade = 2;
        else
            g->capacidade *= 2;

        g->arestas = realloc(g->arestas, g->capacidade * sizeof(Aresta));
        if (g->arestas == NULL) {
            printf("Erro de memória\n");
            exit(1);
        }
    }


    //criar nova aresta
    Aresta a;
    a.o = o;
    a.d = d;
    a.custo = custo;
    //coloca no vetor e adciona um no quantidade de arestas
    g->arestas[g->n_arestas] = a;
    g->n_arestas++;
}

void ler_arquivo(Grafo *g, const char *nome_arquivo) {
    FILE *arq = fopen(nome_arquivo, "r");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo %s\n", nome_arquivo);
        exit(1);
    }

    // lê as arestas linha por linha
    int o, d, p;
    while (fscanf(arq, "%d %d %d", &o, &d, &p) == 3) {
        inserir_arestas(g, o, d, p);
    }

     // Atualiza número de vértices
    if (o > g->n_vertices) g->n_vertices = o;
    if (d > g->n_vertices) g->n_vertices = d;

    fclose(arq);
}

int comparar_arestas(const void *a, const void *b) {
    const Aresta *A = (const Aresta *)a;
    const Aresta *B = (const Aresta *)b;
    return A->custo - B->custo;   // crescente
}

//quick sort
void ordenar_arestas(Grafo *g){
    qsort(g->arestas, g->n_arestas, sizeof(Aresta), comparar_arestas);
}