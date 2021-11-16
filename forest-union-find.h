#ifndef FOREST_UNION_FIND
#define FOREST_UNION_FIND



typedef struct _inverted_tree
{
	int vertex;
	int rank;
	struct _inverted_tree * parent;
}InvertedTree;



#include "graph.h"
#include "edges.h"

#include "forest-union-find.h"

InvertedTree * makeSet(int vertex);

InvertedTree * findSet(InvertedTree * tree);


int unionByRank(InvertedTree * x, InvertedTree * y);


#endif // !FOREST_UNION_FIND