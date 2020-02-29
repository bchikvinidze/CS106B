/*
 * File: main.cpp
 * --------------
 * This is a blank C++ source file.
 */

#include <iostream>
#include "console.h"
#include <string>
#include "simpio.h"
#include "vector.h"
#include "set.h"
#include "deque.h"
using namespace std;

//reverse ornairad:
//void reverse(){
//	tail = head;
//	Cell * swapper = head;
//	head = NULL;
//	while(swapper != NULL){
//		Cell * next = swapper->next;
//		swapper->next = head;
//		head = swapper;
//		swapper = next;
//	}	
//}
//
//Node* reverseLL(Node* &list) {
//	if(list->next == NULL)
//		return list;
//	Node* result = reverseLL(list->next);
//	Node* cur = result;
//	while(cur->next != NULL){
//		cur = cur->next;
//	}
//	cur->next = list;
//	list->next = NULL;
//	return result;
//}



int main(){

	return 0;
}
//
//
//struct TreeNode {
//	string value;
//	Vector<TreeNode*> children;
//};
//
//struct SpaghettiNode {
//	string value;
//	SpaghettiNode* parent;
//};
//
//void freeSpaghettiStack(Set<SpaghettiNode*> leaves){
//	if(leaves.isEmpty())
//		return;
//	Set<SpaghettiNode*> toDelete;
//	foreach(SpaghettiNode* node in leaves){
//		SpaghettiNode* cell = node->parent;
//		toDelete.add(node);
//		node = node->parent;
//	}
//	foreach(SpaghettiNode* node in toDelete){
//		delete node;
//	}
//}
//
//void wrapper1(TreeNode* root, Set<SpaghettiNode*> &result, SpaghettiNode* parent){
//	if(root == NULL){
//		return;
//	}
//	SpaghettiNode* newNode = new SpaghettiNode;
//	newNode->parent = parent;
//	newNode->value = root->value;
//	if(root->children.size() == 0){
//		result.add(newNode); // e.i. LEAF aris.
//	} else {
//		foreach(TreeNode* child in root->children){
//			wrapper1(child, result, newNode);
//		}
//	}
//}
//
//Set<SpaghettiNode*> spaghettify(TreeNode* root){
//	Set<SpaghettiNode*> result;
//	SpaghettiNode* parent = NULL; 
//	wrapper1(root, result, parent);
//	return result;
//}
//
//
//int main(){
//	TreeNode* head = new TreeNode;
//	TreeNode* child1 = new TreeNode;
//	TreeNode* child2 = new TreeNode;
//	TreeNode* child3 = new TreeNode;
//	TreeNode* child11 = new TreeNode;
//	TreeNode* child12 = new TreeNode;
//	TreeNode* child13 = new TreeNode;
//	head->value = "head";
//	child1->value = "1";
//	child2->value = "2";
//	child3->value = "3";
//	child11->value = "11";
//	child12->value = "12";
//	child13->value = "13";
//
//	Vector<TreeNode*> childrenHead;
//	Vector<TreeNode*> children1;
//	Vector<TreeNode*> children2;
//	Vector<TreeNode*> children3;	
//	Vector<TreeNode*> children11;
//	Vector<TreeNode*> children12;
//	Vector<TreeNode*> children13;
//	children1 += child11, child12, child13;
//	child1->children = children1;
//	child2->children = children2;
//	child3->children = children3;
//	childrenHead += child1, child2, child3;
//	head->children = childrenHead;
//	
//
//	Set<SpaghettiNode*> result = spaghettify(head);
//	foreach (SpaghettiNode* sp in result) {
//		SpaghettiNode* node = sp;
//		while (node != NULL) {
//			cout << node->value;
//			if (node->parent != NULL) 
//				 cout << " -> ";
//			else 
//				cout << ".";
//			node = node->parent;
//		}
//		cout << endl;
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
////
////
////
////
////
////
////struct Node {
////	bool isWord;
////	Node* children[26];
////};
////
////void wrapper(Node* root, string pattern, Vector<string>& result, string current){
////	if(pattern == "" && root->isWord = true){ // marto am shemtxvevashi vamatebt result-shi.
////		result.add(current);
////		return;
////	}
////	if(root == NULL)
////		return;
////	
////	if(pattern[0] != '*' && pattern[0] != '?'){
////		Node* nextLetter = root->children[pattern[0]-'a'];
////		current = current + pattern[0];
////		wrapper(nextLetter, pattern.substr(1), result, current);	
////	} else if(pattern[0] == '?'){
////		for(int i = 0; i < 26; i++){
////			Node* nextLetter = root[i];
////			pattern[0] = 'a'+i;
////			wrapper(nextLetter, pattern.substr(1), result, current);
////		}
////	} else { // pattern[0] == '*'
////		wrapper(root, pattern.substr(1), result, current); // roca arafrit ar chavanacvlet;
////		wrapper(root, '?' + pattern, result, current);
////	}
////}
////
////void wildcardSearch(Node* root, string pattern, Vector<string>& result){
////	wrapper(root, pattern, result, "");	
////}
////
////
////int main(){
////	
////	return 0;
////}
////
////
////
////
////
////
////
////
//////
//////int main(){
//////	int a = 1;
//////	int b = 2;
//////	int c = 3;
//////	deque<int> deq;
//////	deq.pushFront(a);
//////	deq.pushBack(c);
//////	deq.pushFront(b);
//////	cout << deq.getFront() << endl;
//////	cout << deq.getBack() << endl;
//////	cout << deq.getFront() << endl;
//////	cout << deq.getBack() << endl;
//////	return 0;
//////}
////
//////template <typename Type>
//////void insertionSort(Vector<Type> &vec){
//////	for(int i = 0; i < vec.size(); i++){
//////		for(int j = i - 1; j >= 0; j--){
//////			if(vec[i] < vec[j]) {
//////				swap(vec, i, j);
//////			} 
//////		}
//////	}
//////}
////
////
////
//////
//////int partition(Vector<int>& v, int start, int finish){
//////	int pivot = v[start];
//////	int lh = start+1;
//////	int rh = finish;
//////	while(true){
//////		while(lh < rh && v[rh] >= pivot) rh--;
//////		while(lh < rh && v[lh] < pivot) lh++;
//////		if(lh == rh) break;
//////		int temp = v[lh];
//////		v[lh] = v[rh];
//////		v[rh] = temp;
//////	}
//////	if(pivot <= v[lh]) return start;
//////	v[start] = v[lh];
//////	v[lh] = pivot;
//////	return lh;
//////}
//////
//////void quickSortInRange(Vector<int> &v, int start, int finish){
//////	if(start>=finish) return;
//////	int boundary = partition(v, start, finish);
//////	quickSortInRange(v, start, boundary-1);
//////	quickSortInRange(v, boundary+1, finish);
//////}
//////
//////void quickSort(Vector<int> &v) {
//////	quickSortInRange(v, 0, v.size()-1);
//////}
//////
//////int main() {
//////	Vector<int> v;
//////	v.add(3);
//////	v.add(5);
//////	v.add(1);
//////	v.add(4);
//////	v.add(2);
//////	quickSort(v);
//////	for (int i = 0; i < v.size(); i++) {
//////		cout << v[i] << endl;
//////	}
//////	return 0;
//////}
////////
////////struct intList {
////////	int val;
////////	intList* next;
////////};
////////
////////intList* findMinAndDelete(intList* &head) {
////////	intList * currentMin = head;
////////	intList * prevMin;
////////	intList * current = head->next;
////////	intList * prevCurrent = head;
////////	while(current != NULL){
////////		if(current->val < currentMin->val){
////////			currentMin = current;
////////			prevMin = prevCurrent;
////////		}
////////		prevCurrent = current;
////////		current = current->next;
////////	}
////////	if(currentMin == head){
////////		head = head->next;
////////	} else {
//////		prevMin->next = currentMin->next;
//////	}
//////	return currentMin;
//////}
//////
//////void sortList(intList* &head) {
//////	if(head == NULL)
//////		return;
//////	intList* newHead = findMinAndDelete(head);
//////	newHead->next = head;
//////	head = newHead;
//////	sortList(head->next);
//////}
//////
//////int main() {
//////	intList* list = new intList[3];
//////	intList* arrayFrontPointerForDelete = list;
//////	list[0].next = list + 1;
//////	list[0].val = 3;
//////	list[1].next = list + 2;
//////	list[1].val = 1;
//////	list[2].val = 2;
//////	list[2].next = NULL;
//////	sortList(list);
//////	for (intList* curPtr = list; curPtr != NULL; curPtr = curPtr -> next) {
//////		cout << curPtr -> val << endl;
//////	}
//////	delete[] arrayFrontPointerForDelete;
//////	return 0;
//////}
////
////
