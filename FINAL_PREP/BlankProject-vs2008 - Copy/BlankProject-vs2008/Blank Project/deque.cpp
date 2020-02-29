
#include "deque.h"
template <typename Type>
deque<Type>::deque(void){
	length = 0;
	front = new Node;
	back = new Node;
	front->prev = NULL;
	front->next = back;
	back->prev = front;
	back->next = NULL;
}

template <typename Type>
deque<Type>::~deque(void){
	Node * ptr = front;
	while(front != NULL){
		Node * tmp = front;
		front = front->next;
		delete tmp;
	}
}

template <typename Type>
bool deque<Type>::isEmpty(){
	return (length == 0);
}

template <typename Type>
void deque<Type>::pushFront(Type T){
	Node * newNode = new Node;
	newNode->T = T;
	newNode->prev = front;
	newNode->next = front->next;
	front->next = newNode;
	newNode->next->prev = newNode; // es mnishvnelovani adgilia
	length++;
}

template <typename Type>
void deque<Type>::pushBack(Type T){
	Node * newNode = new Node;
	newNode->T = T;
	newNode->next = back;
	newNode->prev = back->prev;
	back->prev = newNode;
	newNode->prev->next = newNode;
	length++;
}

template <typename Type>
Type deque<Type>::getFront(){
	if(isEmpty())
		error("mda.");
	Type result = front->next->T;
	Node * tmp = front->next;
	front->next = tmp->next;
	tmp->next->prev = front;
	delete tmp;
	length--;
	return result;
}

template <typename Type>
Type deque<Type>::getBack(){
	if(isEmpty())
		error("mda.");
	Type result = back->prev->T;
	Node * tmp = back->prev;
	back->prev = tmp->prev;
	tmp->prev->next = back;
	length--;
	delete tmp;
	return result;	
}

template class deque<int>;
template class deque<double>;