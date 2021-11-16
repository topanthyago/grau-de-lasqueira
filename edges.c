#include "edges.h"
#include <stdio.h>
#include <stdlib.h>


Edge * allocateEdgeArray(int qtd)
{
	return (Edge *) calloc(sizeof(Edge), qtd);
}

void freeEdgeArray(Edge * edge)
{
	free(edge);
}

int cmpInt(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int cmpEdge(const void * a, const void * b)
{
	const Edge   * aa = (const Edge *) a;
	const Edge * bb = (const Edge *) b;
   return ( cmpInt(&(aa->w), &(bb->w) ));
}


void readEdgeArray(Edge * edge, int qtd)
{
	if (!edge)
		return;
	int i=0;
	for (i=0; i<qtd; i++)
	{
		scanf("%d %d %d", &(edge[i].u),&(edge[i].v), &(edge[i].w));
	}
}
void printEdge(Edge * vet)
{
	printf("%d\t%d\t%d\n", vet->u, vet->v, vet->w);
}


void printEdgeArrayTab(Edge * vet, int qtd)
{
	int i=0;
	
	printf("U\tV\tW\n");
	for (i=0; i<qtd; i++)
	{
		printEdge(&vet[i]);
	}
}

Edge * allocateAndReadEdgeArray(int qtd)
{
	Edge * vet = allocateEdgeArray(qtd);
	readEdgeArray(vet, qtd);
	return vet;
}

void sortEdgeArray(Edge * edge, int qtd)
{
	qsort(edge, qtd, sizeof(Edge), cmpInt);
}