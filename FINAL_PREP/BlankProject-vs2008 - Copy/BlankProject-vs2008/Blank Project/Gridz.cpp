
#include "Gridz.h"
#include "error.h"
template <typename type>
Gridz<type>::Gridz(){
	start = NULL;
	r = 0;
	c = 0;
}
template <typename type>
Gridz<type>::Gridz(int nRows, int nCols){
	Node ** r = new Node*[nRows];
	for(int i = 0; i < nRows; i++){
		Node * c = new Node[nCols]; // default value-ebs ar vwer, dae tviton chaweros rac unda. 
		r[i] = c;
	}
	start = r;
	r = nRows;
	c = nCols;
}
template <typename type>
Gridz<type>::~Gridz(){
	for(int i = 0; i < r; i++){
		Node * row = start[i];
		while(row != NULL){
			Node * deleteNode = row;
			row = row->next;
			delete deleteNode;
		}
	}
	delete[] start;
}
template <typename type>
type Gridz<type>::getAt(int row, int col){
	if(row > r || col > c)
		error("Wat. check ur numberz bro.");
	Node * currentRow = start[row];
	for(int i = 0; i < col; i++)
		currentRow = currentRow->next;
	return currentRow->val;
}
template <typename type>
void Gridz<type>::setAt(int row, int col, type value){
	if(row > r || col > c)
		error("Wat. check ur numberz bro.");
	Node * currentRow = start[row];
	for(int i = 0; i < col; i++)
		currentRow = currentRow->next;
	currentRow->val = value;
}
template <typename type>
void Gridz<type>::resize(int newRows, int newCols){ // ideashi reshape aris. 
	/* Node ** newStart = new Node*[newRows];
	for(int i = 0; i < newRows; i++){
		Node * c = new Node[newCols];
		newStart[i] = c;
	} 

	int count = 0; // ramdeni elementis gadakopireba miwevs
	if(newRows * newCols > r*c) // yvela chaeteva
		count = r*c;
	else
		count = newRows * newCols;

	int st = 0;
	Node * current = start[st];
	for(int i = 0; i < c; i++){
		newStart 
	}
	start = newStart; */ // mdaa rtulia es. davikidot
}

template <typename type>
bool Gridz<type>::inBounds(int row, int col){
	if(row > r || col > c)
		return false;
	return true;
}
template <typename type>
int Gridz<type>::numRows(){
	return r;
}
template <typename type>
int Gridz<type>::numCols(){
	return c;
}

//template <typename type>
//type & Gridz<type>::operator[][](int row, int col){
//	return getAt(row, col);
//}
//template <typename type>
//void & Gridz<type>::operator[][](int row, int col, type value){
//	return setAt(row, col, value);
//}

template class Gridz<int>;
template class Gridz<double>;

