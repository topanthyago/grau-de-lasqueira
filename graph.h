#ifndef GRAPH_ADJACENT_LIST_INCLUDED
#define GRAPH_ADJACENT_LIST_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "src/lista.h"
typedef struct adjacent_list_graph
{
    Lista ** lista;
    char * flag; 
    int qtd_lista;
}ALGraph;

typedef struct _TIPO_GRAPH
{
	int vertice;
	int valor;
}TIPO_GRAPH;


void cleanFlag(ALGraph * gp);

TIPO makeTuple(int _vertice, int _valor);
ALGraph *  createGraph(int vertices);
void freeGraph(ALGraph * gp);
int insertEdgeInGraph(ALGraph * gp, int u, int v, int w);
void printGraph(ALGraph * gp);


#endif // !GRAPH_ADJACENT_LIST_INCLUDED 