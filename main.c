#include <stdio.h>
#include "graph.h"
#include "edges.h"
#include "forest-union-find.h"
#include "src/lista.h"



int maior(int a, int b)
{
	return (a>b)? a : b;
}
int MaiorNumeroDeBuracosEmUmaRuaDeUmaArvoreMinima(ALGraph * gp,  int origem, int destino){
	if (!gp)
		return 0;
	if (origem==destino)
		return 0;
	
	//printf("Visitei:\n", origem); 
	
	if ( gp->flag[origem] == 10)//se o vertice ja foi visitado
	{
		return 0;
	}

	gp->flag[origem] = 10;//marcado como visitado

	int dist = 0;
	
	No * atual = gp->lista[origem]->inicio;

	while(atual)
	{
		if (atual->chave.vertice == destino)
		{
			return atual->chave.valor;
		}
		else{
			dist =  MaiorNumeroDeBuracosEmUmaRuaDeUmaArvoreMinima(gp,atual->chave.vertice, destino);
			if (dist)
			{
				return maior(dist, atual->chave.valor);
			}
		}
		atual = atual->prox;
	}
	return 0;

	//em busca 


	return 0;
}





int main()
{
	int i = 0;
	int N, M;
	int U, V, W;
	scanf("%d %d", &N, &M);

	//Conjunto de Arestas ordernadas
	//para pensarmos enquanto uma lista;
	Edge * vetEdges = allocateAndReadEdgeArray(M);
	sortEdgeArray(vetEdges, M);
	int arestasConsumidas = 0;

	//Conjunto de Vértices, enquanto floresta
	InvertedTree ** floresta = (InvertedTree ** )malloc(sizeof(InvertedTree *) * N);
	int qtdFloresta = N;//diminui a cada Union
	for (int i=0; i<N; i++)
	{
		floresta[i] = makeSet(i);
	}
	ALGraph * grafo = createGraph(N);

	for (i=0; i < M; i++)
	{
		//printf("%d %d %d\n", vetEdges[i].u, vetEdges[i].v, vetEdges[i].w);
		if (unionByRank(floresta[vetEdges[i].u], floresta[vetEdges[i].v]))
		{
			insertEdgeInGraph(grafo, vetEdges[i].u, vetEdges[i].v, vetEdges[i].w);
		}
		else{
			
		}
	}
	//printGraph(grafo);

	int qtd;
	int dist = 0;
	scanf("%d", &qtd);

	for (int i=0; i<qtd; i++)
	{

		cleanFlag(grafo);
		scanf("%d %d", &U, &V);
		//printf("\nU:%d\tV:%d\n", U, V);
		dist = MaiorNumeroDeBuracosEmUmaRuaDeUmaArvoreMinima(grafo, U, V);
		
		if (dist)
			printf("%d\n", dist);
		else
			printf("sem rota\n");
		
	}
}
//void kruskal(Graph * )