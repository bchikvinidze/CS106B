
#include "myString.h"

myString::myString(void){
	length2 = 0;
	head = NULL;
}
myString::~myString(void){
	while(head != NULL){
		Cell* newCell = head->next;
		delete head;
		head = newCell;
	}
}

string myString::getValue(){
	string result;
	Cell* cursor = new Cell;
	cursor = head;
	while(cursor != NULL){
		result += cursor->ch;
		cursor = cursor->next;
	}
	return result;
}

void myString::setValue(string s){
	while(head != NULL){
		Cell* newCell = head->next;
		delete head;
		head = newCell;
	}
	if(s.length() == 0) return;
	Cell * cur = new Cell;
	cur->ch = s[0];
	cur->next = NULL;
	head = cur;
	for(int i = 1; i < s.length(); i++){
		Cell* newCell = new Cell;
		newCell->ch = s[i];
		newCell->next = NULL;
		cur->next = newCell;
		cur = newCell;
	}
	length2 = s.length();
}

Cell* myString::createList(string str){
	if(s.length() == 0) return NULL;
	Cell * cur = new Cell;
	cur->ch = s[0];
	cur->next = NULL;
	Cell* result = cur;
	for(int i = 1; i < s.length(); i++){
		Cell* newCell = new Cell;
		newCell->ch = s[i];
		newCell->next = NULL;
		cur->next = newCell;
		cur = newCell;
	}
	return result;
}

string myString::getValueWrapper(Cell * cur, int left){
	if(left == 0)
		return "";
	return cur->ch + getValueWrapper(cur->next, left - 1);
}

string myString::substr2(int index, int len){
	Cell * cur = head;
	for(int i = 0; i < index; i++){
		cur = cur->next; // me-index-e dadgoma cur-it.
	}
	return getValueWrapper(cur, len);
}

int myString::find(string s){
	Cell * cur = head;
	for(int i = 0; i < length2 - s.length(); i++){
		string str = getValueWrapper(cur, s.length());
		if(s = str)
			return i;
		cur = cur->next;
	}
	return -1;
}

int myString::size(){
	return length2;
}

void myString::insert(int index, string s){ // indeqsi gacda tu ara sazgvrebs magis shemowmebac gvinda ideashi.
	length2 += s.length();
	Cell * newHead = createList(s);
	Cell * tail = newHead;
	while(tail->next != NULL)
		tail = tail->next;
	if(index == 0){
		tail->next = head;
		head = newHead;
		return;
	}
	for(int i = 0; i < index - 1; i++){
		Cell* cur = head;
		cur = cur->next;
	}	
	tail->next = cur->next;
	cur->next = newHead;
}
void myString::remove(int index, int len){
	length2 -= len;
	Cell * cur = head;
	for(int i = 0; i < index - 1; i++){
		
	}
}
