#ifndef EDGES_INCLUDED
#define EDGES_INCLUDED

typedef int TIPO_EDGE;

typedef struct _edge{
	TIPO_EDGE w;
	int v;
	int u;
}Edge;
int cmpEdge(const void * a, const void * b);

void sortEdgeArray(Edge * edge, int qtd);
void printEdge(Edge * vet);
Edge * allocateEdgeArray(int qtd);

Edge * allocateAndReadEdgeArray(int qtd);
void freeEdgeArray(Edge * ptr);

int cmpInt(const void * a, const void * b);
void readEdgeArray(Edge * vet, int qtd);

void printEdgeArrayTab(Edge * vet, int qtd);








#endif // !EDGES_INCLUDED