#include "DBTree.h"

DBTree::DBTree(){
	root = NULL;
}

void deleteTree(tree* tr){
	if(tr == NULL)
		return;
	tree* lft = tr->left;
	tree* md = tr->mid;
	tree* rgt = tr-right;
	delete tr;
	deleteTree(lft);
	deleteTree(md);
	deleteTree(rgt);
}	

DBTree::~DBTree(){
	while(root != NULL){
		deleteTree(root->left);
		deleteTree(root->right);
		deleteTree(root->mid);
	}
}

bool contains(int value, tree*& subtree){//vanaxineb subtree-s rogor icvleba :D
	if(subtree->val1 == value || subtree->val2 == value)
		return true;
	if(subtree == NULL){
		return false;
	} else if(subtree->val1 == SENTINEL && value != subtree->val2){
		return false;
	} else if(subtree->val2 == SENTINEL && value != root->val1){
		return false;
	} else if(value < root->val1){
		if(contains(value, subtree->left)) return true;
	} else if(value > subtree->val2){
		if(contains(value, root->right)) return true;
	} else if(value > subtree->val1 && value < subtree->val2){
		if(contains(value, subtree->mid)) return true;
	} 
	return false;
}

void insertIntotree(int value, tree*& subtree){
	if(subtree == NULL){
		tree* newTree = new tree;
		newTree->val1 = value;
		newTree->val2 = SENTINEL;
		newTree->left = NULL;
		newTree->right = NULL;
		newTree->mid = NULL;
		root = newTree;
	} else if(subtree->val1 == SENTINEL && value != subtree->val2){
		subtree->val1 = value;
	} else if(subtree->val2 == SENTINEL && value != root->val1){
		subtree->val2 = value;
	} else if(value < root->val1){
		insertIntotree(value, subtree->left);
	} else if(value > subtree->val2){
		insertIntotree(value, root->right);
	} else if(value > subtree->val1 && value < subtree->val2){
		insertIntotree(value, subtree->mid);
	} 
	//tu arada eseigi ukve yofila es value da agar unda chavamatot
}

void DBTree::Insert(int value){
	insertIntoTree(value, root);
}

void DBTree::Remove(int value){
	tree* track = root;
	if(contains(value, track)){ // track am dros wesit (da chemi ganzraxvit) sheicavs values.
		if(track->val1 == SENTINEL || track->val2 == SENTINEL){ //case1
			tree* tmp = track;
			delete track;
			tmp = NULL;
		} else if(track->left == NULL && track->right == NULL && track->mid == NULL){//case2 
			if(track->val1 == value){
				track->val1 = track->val2;
				track->val2 = SENTINEL;
			}
		} else {
			if(track->val1 == value){
				int newVal = largest(track->left)->val2;
				largest(track->left)->val2 = SENTINEL;
			} else {
				int newVal = smallest(track->right)->val1;
				smallest(track->right)->val1 = SENTINEL;
			}
		}
	}
}

tree* smallest(tree*& subtree){ 
	if(subtree == NULL)
		return subtree;
	return smallest(subtree->left);
}

tree* largest(tree*& subtree){
	if(subtree == NULL)
		return subtree;
	return smallest(subtree->right);
}
