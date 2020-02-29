/*************************************************************
 * File: pqueue-doublylinkedlist.cpp
 *
 * Implementation file for the DoublyLinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-doublylinkedlist.h"
#include "error.h"

DoublyLinkedListPriorityQueue::DoublyLinkedListPriorityQueue() {
	length = 0;
	head = NULL;
	resultCell = NULL;
}

DoublyLinkedListPriorityQueue::~DoublyLinkedListPriorityQueue() {
	while(head != NULL){
		Cell *nextCell = head->next;
		delete head;
		head = nextCell;
	}
}

int DoublyLinkedListPriorityQueue::size() {
	return length;
}

bool DoublyLinkedListPriorityQueue::isEmpty() {
	return size() == 0;
}

void DoublyLinkedListPriorityQueue::enqueue(string value) {
	Cell *newCell = new Cell;
	newCell->str = value;
	newCell->prev = NULL;
	if(head != NULL){
		head->prev = newCell;
	}
	newCell->next = head;
	head = newCell;
	length++;
}

string DoublyLinkedListPriorityQueue::peek() {
	if(isEmpty())
		error("Queue is empty.");
	resultCell = head;
	Cell *trackCell = head;
	while(trackCell->next != NULL){
		if(resultCell->str > trackCell->next->str){
			resultCell = trackCell->next;
		}
		trackCell = trackCell->next;
	}
	string result = resultCell->str;
	return result;
}

string DoublyLinkedListPriorityQueue::dequeueMin() {
	string result = peek();
	if(size() == 1){
		head = NULL;
	} else if(resultCell->next == NULL){
		resultCell->prev->next = NULL;
	} else if(resultCell->prev == NULL){
		head = resultCell->next;
		resultCell->next->prev = NULL;
	} else {
		resultCell->prev->next = resultCell->next;
		resultCell->next->prev = resultCell->prev;
	}
	length--;
	return result;
}

