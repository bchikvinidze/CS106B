#include "BST_H.h"

template <typename ElemType>
BST_H::BST_H(){
	root = NULL;
}

template <typename ElemType>
BST_H::~BST_H(){
	deallocateSubtree(node* root)
}

template <typename ElemType>
bool BST_H::contains(ElemType element){
	if(findNode(root, element)->value == element)
		return true;
	return false;
}

template <typename ElemType>
void BST_H::insert(ElemType element){
	if(root == NULL){
		node* newNode = new Node;
		newNode->value = element;
		newNode->left = NULL;
		newNode->right = NULL;
		root = newNode;
	} else if(contains(element)){
		return;
	} else {
		node* insert = findNode(root, element);
		//axla insert NULL-s udris
		insert = new Node;
		insert->value = element;
		insert->right = NULL;
		insert->left = NULL;
	}
}

template <typename ElemType>
void BST_H::remove(ElemType element){
	node* toRemove = findNode(root, element);
	if(toRemove == NULL) 
		return;
	if(toRemove->left == NULL){
		node* tmp = toRemove;
		toRemove = toRemove->right;
		delete tmp;
	} else {
		node* leftMax = findMax(toRemove->left);
		toRemove->value = leftMax->value;
		node* tmp = leftMax;
		leftMax = leftMax->left;
		delete tmp;
	}
}

template <typename ElemType>
ElemType BST_H::maxElement(){
	return findMax(root)->value;
}

template <typename ElemType>
void deallocateSubtree(node* subtree){
	while(subtree != NULL){
		deallocateSubtree(subtree->left);
		deallocateSubtree(subtree->right);
		delete subtree;
	}
}

template <typename ElemType>
node*& findNode(node*& subtree, ElemType element){
	if(subtree == NULL)
		return NULL;
	if(subtree->value == element)
		return subtree;
	if(subtree->value > element)
		return findNode(subtree->left, element);
	return findNode(subtree->right, element);
}

template <typename ElemType>
node*& findMax(node*& subtree){
	if(subtree == NULL)
		return NULL;
	if(subtree->right == NULL)
		return subtree;
	return findMax(subtree->right);
}

template <typename ElemType>
void insertInSubtree(node*& subtree, node* newNode){
	
}

template <typename ElemType>
void rotateRight(node*& subtree){
	
}

template <typename ElemType>
void rotateLeft(node*& subtree){
	
}

template <typename ElemType>
void insert2(ElemType element){
	
}