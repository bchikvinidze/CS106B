/*************************************************************
 * File: pqueue-heap.cpp
 *
 * Implementation file for the HeapPriorityQueue
 * class.
 */
 
#include "pqueue-heap.h"
#include "error.h"

HeapPriorityQueue::HeapPriorityQueue() {
	length = 0;
	allocLen = START_SIZE;
	arr = new string[START_SIZE];
}

HeapPriorityQueue::~HeapPriorityQueue() {
	delete []arr;
}

int HeapPriorityQueue::size() {
	return length;
}

bool HeapPriorityQueue::isEmpty() {
	return size() == 0;
}

void HeapPriorityQueue::swap(int a, int b) {
	string element = arr[a];
	arr[a] = arr[b];
	arr[b] = element;
}

void HeapPriorityQueue::bubbleUp(){
	for(int i = size(); i > 1; i /= 2){ 
		if(arr[i-1] < arr[i/2-1])
			swap(i-1, i/2-1);
		else 
			break;
	}
}

void HeapPriorityQueue::enqueue(string value) {
	if(length == allocLen){
		allocLen *= 2;
		string *copy = new string[allocLen];
		for(int i = 0; i < length; i++)
			copy[i] = arr[i];
		delete []arr;
		arr = copy;
	}
	arr[length] = value;
	length++;
	if(size() != 1)
		bubbleUp();
}

string HeapPriorityQueue::peek() {
	if(isEmpty())
		error("Queue is empty.");
	return arr[0];
}

void HeapPriorityQueue::bubbleDown(int pos = 1){
	if(pos <= size()/2){
		if(size() >= pos*2+1 && arr[pos*2-1] > arr[pos*2]){
			if(size() >= pos*2+1 && arr[pos-1] > arr[pos*2]){
				swap(pos-1, pos*2);
				bubbleDown(pos*2+1);
			}
		} else if(size() > 1 && arr[pos-1] > arr[pos*2-1]){
			swap(pos-1, pos*2-1);
			bubbleDown(pos*2);
		}
	}
}

string HeapPriorityQueue::dequeueMin() {
	string result = peek();
	if(size() != 1) 
		swap(0,size()-1);
	length--;
	if(size() != 1)
		bubbleDown();
	return result;
}

