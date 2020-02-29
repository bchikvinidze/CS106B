#pragma once

#include "error.h"
using namespace std;

template <typename Type>
class deque
{
public:
	deque();
	~deque();
	void pushFront(Type T);
	void pushBack(Type T);
	Type getFront();
	Type getBack();
	bool isEmpty();
private:
	struct Node{
		Node * prev;
		Type T;
		Node * next;
	};
	int length;
	Node * front;
	Node * back;
};
