#include "union_find.h"
#include <stdio.h>
#include <stdlib.h>

UnionFind criar_unionfind(int n){
    UnionFind uf;
    uf.tamanho = n;

    uf.pai = malloc(n * sizeof(int));
    uf.rank = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        //cada indice tem pai inicialmente  igual ele mesmo
        uf.pai[i] = i;
        uf.rank[i] = 0;
    }
    return uf;

}

int find(UnionFind *uf, int x){
    if (uf->pai[x] != x){
        uf->pai[x] = find(uf, uf->pai[x]);
    }
    return uf->pai[x];

}

void unir(UnionFind *uf, int a, int b){
    int raizA = find(uf, a);
    int raizB = find(uf, b);

    if (raizA == raizB) return; //mesmo conjunto , precisa unir

    // faz união de raizes comparando rank par ver quem vai ser o "raiz"
    if (uf->rank[raizA] < uf->rank[raizB]) {
        uf->pai[raizA] = raizB;
    }
    else if (uf->rank[raizA] > uf->rank[raizB]) {
        uf->pai[raizB] = raizA;
    }

    //se rank igual escolhi primeiro raiz como o "raiz"
    else {
        uf->pai[raizB] = raizA;
        uf->rank[raizA]++;
    }
}

void liberar_unionfind(UnionFind *uf){
    free(uf->pai);
    free(uf->rank);
}