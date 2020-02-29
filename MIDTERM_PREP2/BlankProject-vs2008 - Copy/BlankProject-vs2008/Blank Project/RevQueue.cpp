
#include "RevQueue.h"

RevQueue::RevQueue()
{
	head = tail = NULL;
}

RevQueue::~RevQueue()
{
	while(head != NULL){
		Cell * newCell = head;
		head = head->next;
		delete newCell;
	}	
}

void RevQueue::reverseWrapper(Node *& node){// gadacemul paramets ar viyeneb
	tail = head;
	Cell * cur = head;
	head = NULL;
	while(cur != NULL){
	  Cell * next = cur->next;
	  cur->next = head;
	  head = cur;
	  cur = next;
	}
}

//Node-s shetrialeba da dabruneba
Cell * dafaq(Cell*&cell){
	if(cell == NULL)
		return cell;
	Cell * result = dafaq(cell->next);
	Cell * temp = result;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = cell;
	cell->next = NULL;
	return result;
}

void RevQueue::reverse(){ // rekursia kai variantiaaaa
	reverseWrapper(head);	
}
