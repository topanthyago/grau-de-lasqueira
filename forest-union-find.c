#include "graph.h"
#include "edges.h"

#include "forest-union-find.h"

InvertedTree * makeSet(int vertex)
{
	InvertedTree * tree = (InvertedTree *) malloc(sizeof(InvertedTree));
	tree->parent = tree;
	tree->rank = 0;
	tree->vertex = vertex;
	return tree;
}

InvertedTree * findSet(InvertedTree * tree)
{
	while(tree->parent != tree)
		tree = tree->parent;
	return tree;
}


int unionByRank(InvertedTree * x, InvertedTree * y)
{
	InvertedTree * rx;
	InvertedTree * ry;
	rx = findSet(x);
	ry = findSet(y);
	if (rx == ry)//ja sao da mesma arvore
		return 0;
	if (rx->rank > ry->rank)
		ry->parent = rx;
	else
	{
		rx->parent = ry;
		if (rx->rank == ry->rank)
			ry->rank++;
	}
	return 1;
}
