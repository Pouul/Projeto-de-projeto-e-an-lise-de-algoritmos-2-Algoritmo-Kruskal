#ifndef UNION_FIND_H
#define UNION_FIND_H

// Estruturas
typedef struct {
    int *pai;
    int *rank;
    int tamanho;
} UnionFind;

// Funções
UnionFind criar_unionfind(int n);
int find(UnionFind *uf, int x);
void unir(UnionFind *uf, int a, int b);
void liberar_unionfind(UnionFind *uf);

#endif
