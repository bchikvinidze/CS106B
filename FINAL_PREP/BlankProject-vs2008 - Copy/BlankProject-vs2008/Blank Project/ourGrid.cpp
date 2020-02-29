#include "ourGrid.h"

ourGrid::ourGrid(){
	int nRows = 0;
	int nCols = 0;
	head = NULL;
}

void ourGrid::deleteRow(Node* node){
	Node* nextRow = node->down;
	while(node->right != NULL){
		Node* nxt = node->right;
		delete node;
		node = nxt;
	}
	delete node;
	node = newRow;
}

ourGrid::~ourGrid(){
	while(head != NULL){
		deleteRow(head);
	}
}

void ourGrid::addColumn(){
	if(nRows == 0 || nCols == 0){
		Node* newNode = new Node;
		newNode->down = NULL;
		newNode->right = NULL;
		head = newNode;
	} else {
		for(int i = 0; i < nRows; i++){
			Node* newNode = new Node;
			newNode->right = NULL;
			newNode->down = NULL;
			Node* track = head;
			for(int j = 0; j < nCols; j++){
				track = track->right;
			}
			track->right = newNode;
		}
	}
	nCol++;
}
void ourGrid::addRow(){
	if(nRows == 0 || nCols == 0){
		Node* newNode = new Node;
		newNode->down = NULL;
		newNode->right = NULL;
		head = newNode;
	} else {
		Node* lastNode = head;
		for(int i = 0; i < nRows - 1; i++){
			lastNode = lastNode->down;
		}
		for(int i = 0; i < nCols; i++){
			Node* newNode = new Node;
			newNode->right = NULL;
			newNode->down = NULL;
			if( i == 0 ){
				lastNode->down = newNode;
				lastNode = newNode;
			}
			lastNode->right = newNode;
		}
	}
	nRows++;
}

void ourGrid:: setValue(int row, int col, int value){
	Node* newVal = head;
	for(int i = 0; i < row - 1; i++){
		newVal = newVal->down;
	}
	for(int i = 0; i < col - 1; i++){
		newVal = newVal->right;
	}
	newVal->value = value; 
}
