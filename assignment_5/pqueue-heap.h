/**********************************************
 * File: pqueue-heap.h
 *
 * A priority queue class backed by a binary
 * heap.
 */
#ifndef PQueue_Heap_Included
#define PQueue_Heap_Included

#include <string>
using namespace std;

/* declaring constants */
const int START_SIZE = 1;

/* A class representing a priority queue backed by an
 * binary heap.
 */

class HeapPriorityQueue {
public:
	/* Constructs a new, empty priority queue backed by a binary heap. */
	HeapPriorityQueue();
	
	/* Cleans up all memory allocated by this priority queue. */
	~HeapPriorityQueue();
	
	/* Returns the number of elements in the priority queue. */
	int size();
	
	/* Returns whether or not the priority queue is empty. */
	bool isEmpty();
	
	/* Enqueues a new string into the priority queue. */
	void enqueue(string value);
	
	/* Returns, but does not remove, the lexicographically first string in the
	 * priority queue.
	 */
	string peek();
	
	/* Returns and removes the lexicographically first string in the
	 * priority queue.
	 */
	string dequeueMin();

private:
	int length;
	int allocLen;
	string *arr;
	
	/* Used when element is enqueued to move element's position and correctly place it */
	void bubbleUp();

	/* Used when element is dequeued from the array to fix the standings of strings */
	void bubbleDown(int position);

	/* Used for swapping during bubble up and bubble down process */
	void swap(int a, int b); 
};

#endif
