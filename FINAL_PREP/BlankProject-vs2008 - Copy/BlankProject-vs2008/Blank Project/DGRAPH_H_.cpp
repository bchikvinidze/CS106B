#include "DGRAPH_H_.h"
#include "queue.h"

DGRAPH_H_::DGRAPH_H_(int size){
	numVertices = size;
	numEdges = 0;
	vertices = new Vertex[numVertices];
}
DGRAPH_H_::~DGRAPH_H_(){
	delete [] vertices;
}
int DGRAPH_H_::size(){
	return numVertices;
}
int DGRAPH_H_::edgeCount(){
	return numEdges;
}
void DGRAPH_H_::addEdge(int i, int j){
	if(!hasEdge(i,j)){
		vertices[i].neighbors.add(vertices+j);
		numEdges++;
	}
}
void DGRAPH_H_::removeEdge(int i, int j){
	if(hasEdge(i,j)){
		vertices[i].neighbors.remove(vertices+j);
		numEdges--;
	}
}
bool DGRAPH_H_::hasEdge(int i, int j){
	return vertices[i].neighbors.contains(vertices+j);
}
bool DGRAPH_H_::hasPath(int i, int j){
	Set<Vertex*> visited;
	return hasPathz(vertices+i,vertices+j,visited);
}
bool DGRAPH_H_::hasPathz(Vertex* start, Vertex* end, Set<Vertex*> visited){
	if(start == end)
		return true;
	visited.add(start);
	foreach(Vertex* neighbor in start->neighbors){
		if(!visited.contains(neighbor)){
			if(hasPathz(neighbor, end, visited))
				return true;
		}
	}
	return false;
}

int shortestPath(int i, int j);{
	Queue<Vertex*> q;
	Set<Vertex*> visited;
	q.add(vertices+i);
	visited.add(vertices+i);
	int result = 0;
	while(!q.isEmpty()){
		Queue<Vertex*> neighborz;
		while(!q.isEmpty()){
			Vertex* index = q.dequeue();
			if(vertices+j == index)
				return result;
			for(int n = 0; i < index->neighbors.size(); n++){
				if(!visited.contains(vertices + n)){
					result++;
					visited.add(vertices+n);
					neighborz.add(vertices+n);
				}
			}
		}
		q = neighborz;
		result++;
	}
	return -1;
}

int numComponents(){
	int result = 0;
	Set<Vertex*> visited;
	Queue<Vertex*> q;
	for(int i = 0; i < numVertices; i++){
		if(!visited.contains(vertices + i){
			resilt++;
			q.enqueue(vertices + i);
			visited.add(vertices + i);
			while(!q.isEmpty()){
				Vertex* cur = q.dequeue();
				foreach(Vertex* neighbor in cur->neighbors){
					if(!visited.contains(neighbors)){
						visited.add(neighbor);
						q.enqueue(neighbor);
					}
				}
			}
		}
	}
	return result;
}

