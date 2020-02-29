/*************************************************************
 * File: pqueue-vector.cpp
 *
 * Implementation file for the VectorPriorityQueue
 * class.
 */
 
#include "pqueue-vector.h"
#include "error.h"

VectorPriorityQueue::VectorPriorityQueue() {
	Vector<string> elems;
	indx = -1;
}

VectorPriorityQueue::~VectorPriorityQueue() {
	
}

int VectorPriorityQueue::size() {
	return elems.size();
}

bool VectorPriorityQueue::isEmpty() {
	return size() == 0;
}

void VectorPriorityQueue::enqueue(string value) {
	elems.add(value);
}

string VectorPriorityQueue::peek() {
	if (isEmpty()) {
		error("Error: Queue is empty.");
	}
	string result = elems[0];
	indx = 0;
	for(int i = 0; i < size(); i++){
		if(result > elems[i]){
			result = elems[i];
			indx = i;
		}
	}
	return result;
}

string VectorPriorityQueue::dequeueMin() {
	string result = peek();
	elems.remove(indx);
	return result;
}

