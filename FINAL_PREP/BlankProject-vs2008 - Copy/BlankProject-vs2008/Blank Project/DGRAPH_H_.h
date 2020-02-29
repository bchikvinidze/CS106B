#pragma once

#include "set.h"

class DGRAPH_H_
{
public:
	DGraph(int size);
	~DGraph();
	int size();
	int edgeCount();
	void addEdge(int i, int j);
	void removeEdge(int i, int j);
	bool hasEdge(int i, int j);
	bool hasPath(int i, int j);
	int minimumEdgesInPath(int fromIndex, int toIndex);
private:
	struct Vertex{
		Set<Vertex*> neighbors;
	};
	Vertex* vertices;
	int numVertices;
	int numEdges;
	bool hasPathz(Vertex* v1, Vertex* v2, Set<Vertex*> visited);
};
