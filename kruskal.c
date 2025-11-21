#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "union_find.h"

void kruskal(Grafo *g) {
    //ordenar o grafo, para pririzar os arestas de menor custo
    ordenar_arestas(g);

    //iniciar unionfind
    UnionFind uf = criar_unionfind(g->n_vertices + 1);

    int total = 0;          // contador para verificar numero de elementos percorrido
    int custo_total = 0;    // custo acumulado

    printf("elementos dentro do uf:\n");
    // percorrer o grafo
    for (int i = 0; i < g->n_arestas; i++) {

        int u = g->arestas[i].o;
        int v = g->arestas[i].d;
        int w = g->arestas[i].custo;

        

        // verifica se forma circulo
        if (find(&uf, u) != find(&uf, v)) {

            //Unir se não formar ciclo
            unir(&uf, u, v);

            //printar arestas váridas
            printf("%d %d %d\n", u, v, w);

            custo_total += w;
            total++;

            //se já percorreu todo o grafo para
            if (total == g->n_vertices - 1)
                break;
        }
    }

    printf("\nCusto total = %d\n", custo_total);

    liberar_unionfind(&uf);
}
