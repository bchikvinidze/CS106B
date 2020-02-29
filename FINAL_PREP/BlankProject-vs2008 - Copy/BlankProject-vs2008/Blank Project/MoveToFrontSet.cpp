#include "MoveToFrontSet.h"

MoveToFrontSet::MoveToFrontSet()
{
	head = NULL;
	length = NULL;
}

MoveToFrontSet::~MoveToFrontSet()
{
	while(head != NULL){
		Node* nextNode = head->next;
		delete head;
		head = nextNode;
	}
}

bool MoveToFrontSet::contains(string& str){
	if(length != NULL){
		Node* trackingNode = head;
		Node* prevNode = head;
		if(head->val = str)
			return true;
		while(trackingNode != NULL){
			if(trackingNode->val == str){
				prevNode->next = trackingNode->next;
				trackingNode->next = head;
				head = trakingNode;
				return true;
			}
			prevNode = trackingNode;
			trackingNode = trackingNode->next;
		}
		return false;
	}
	return false;
}
void MoveToFrontSet::add(string& str){
	if(contains(strs))
		return;
	Node* newNode = new Node;
	newNode->val = str;
	newNode->next = head;
	head = newNode;
	length++;
}

void MoveToFrontSet::remove(string& str){
	if(contains(str)){
		Node* node = head;
		head = head->next;
		delete node;
	}
	length--;
}
