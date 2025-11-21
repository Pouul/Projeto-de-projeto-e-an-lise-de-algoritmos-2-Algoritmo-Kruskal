#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// criação do estrutura de dados
typedef struct{
    int o;
    int d;
    int custo;
}Aresta;

// basicamente um vetor de arestas
typedef struct{
    int n_vertices;
    int n_arestas;
    int capacidade;
    Aresta *arestas;
}Grafo;

Grafo novo_grafo();
Aresta nova_aresta(int o, int d, int custo);
void inserir_arestas(Grafo *g, int o, int d, int custo);
void ler_arquivo(Grafo *g, const char *nome_arquivo);
void ordenar_arestas(Grafo *g);

#endif