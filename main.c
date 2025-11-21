//inegrantes
//Jiye Huang RA: 10438990
//Gustavo Kiyoshi Ikeda RA: 10439179
//Pedro Montarroyos de Pinho RA: 10440213

//limitação: maior elemento precisa ser o numero de elemento do grafo

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "kruskal.h"

int main() {
    // criar grafo
    Grafo g = novo_grafo();
    // ler e colocar no grafo
    ler_arquivo(&g, "in.txt");

    printf("Número de arestas lidas: %d\n", g.n_arestas);
    printf("Número de vértices estimado: %d\n", g.n_vertices);
    // ordenar o grafo
    ordenar_arestas(&g);

    printf("grafo ordenado\n");

    for (int i = 0; i < g.n_arestas; i++) {
        printf("%d %d %d\n",
            g.arestas[i].o,
            g.arestas[i].d,
            g.arestas[i].custo);
    }

    // Executar Kruskal
    printf("\n==== KRUSKAL ====\n");
    kruskal(&g);

    free(g.arestas);
    return 0;
}
