/*************************************************************
 * File: pqueue-linkedlist.cpp
 *
 * Implementation file for the LinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-linkedlist.h"
#include "error.h"

LinkedListPriorityQueue::LinkedListPriorityQueue() {
	length = 0;
	head = NULL;
}

LinkedListPriorityQueue::~LinkedListPriorityQueue() {
	while(head != NULL){
		Cell *nextCell = head->next;
		delete head;
		head = nextCell;
	}
}

int LinkedListPriorityQueue::size() {
	return length;
}

bool LinkedListPriorityQueue::isEmpty() {
	return size() == 0;
}

void LinkedListPriorityQueue::enqueue(string value) {
	Cell *newNode = new Cell;
	Cell *cursor = new Cell;
	Cell *previous = new Cell;
	newNode->str = value;
	cursor = head;
	if(isEmpty()){
		newNode->next = NULL;
		head = newNode;
	} else if(value <= cursor->str){
		newNode->next = cursor;
		head = newNode;
	} else {	
		while(value > cursor->str){
			if(cursor->next == NULL){
				newNode->next = NULL;
				cursor->next = newNode;
				length++;
				return;
			}
			previous = cursor;
			cursor = cursor->next;
		}
		previous->next = newNode;
		newNode->next = cursor;
	}
	length++;
}

string LinkedListPriorityQueue::peek() {
	if(isEmpty())
		error("PQueue is empty.");
	return head->str;
}

string LinkedListPriorityQueue::dequeueMin() {
	string result = peek();
	Cell *temp = head->next;
	delete head;
	head = temp;
	length--;
	return result;
}

