#pragma once

#include "random.h"
const int MIN = 0;
const int MAX = 1000;

template <typename ElemType>
class BST_H
{
public:
	BST_H();
	~BST_H();
	bool contains(ElemType element);
	void insert(ElemType element);
	void insert2(ElemType element); // balansirebistvis p.s. ar shedisoooooo
	void remove(ElemType element);
	ElemType maxElement();
private:
	struct node{
		ElemType value;
		node* right;
		node* left;
	};
	node* root;
	void deallocateSubtree(node* subtree);
	node*& findNode(node*& subtree, ElemType element);
	node*& findMax(node*& subtree);
	void insertInSubtree(node*& subtree, node* newNode);
	void rotateRight(node*& subtree);
	void rotateLeft(node*& subtree);
};
