#include "LinearProbingTable.h"
const int SENTINEL = -1;
const int TABLE_SIZE = 8;

LinearProbingTable::LinearProbingTable(){
	length = 0;	
	for(int i = 0; i < TABLE_SIZE; i++)
		table.add(SENTINEL);
}

LinearProbingTable::~LinearProbingTable(){

}

bool contains(int value){
	
}

void add(int value){
	int code = hashCode(value) % vec.size();
	if(vec[code].size() == 0){
		vec[code].add(value);
		return;
	} 
	if(
}
int size(){
	return length;
}
bool isEmpty(){
	return size() == 0;
}

void rehash(){
	Vector<int> newVec(vec.size()*2);
	for(int i = 0; i < vec.size(); i++){
		int code = hashCode(vec[i]) % (vec.size()*2);
		newVec[code] = vec[i];
	}
}

bool filenameMatches(string filename, string pattern){
	if(pattern.size() == 0 || (patternContainsOnlyStars){
		if(filename.size() == 0)
			return true;
		return false;
	}
	if(pattern[0] == '?' || pattern[0] == filename[0]){
		return(filename.substr(1), pattern.substr(1));
	}
	if(pattern[0] == '*'){
		int l = filename.length();
		for(int i = 0; i < l; i++){
			if(filenameMatches(filename.substr(i), pattern.substr(1))
				return true;
		}
	}
	return false;
}









int hash(String key, int numBuckets);
struct Node {
	String key;
	String value;
	Node * next;
};
int numBuckets;
Node * buckets;

void rehash(int nBuckets){
	Node* newBuckets = new Node; 
	newBuckets->next = NULL;
	for(int i = 0; i < nBuckets-1; i++){
		Node* newBuckets2 = new Node;
		newBuckets2->next = newBuckets;
		newBuckets = newBuckets2;
	} 
	Node* copy = buckets;
	for(int i = 0; i < numBuckets; i++){
		int code = hash(copy->key, nBuckets);
		for(int i = 0; i < code; i++){
			
		}
	}
	buckets = newBuckets;
	delete newBuckets;
}

void rebalance(BSTNode * & root) {
	Vector<BSTNode *> v;
	fillVector(root, v);
	root = rebuildTree(v, 0, v.size() - 1);
}

void fillVector(BSTNode *node, Vector<BSTNode *> & v){
	while(node != NULL){
		fillVector(node->left, v);
		v.add(node);
		fillVector(node->right, v);
	}
}

BSTNode *rebuildTree(Vector<BSTNode *> & v, int start, int end){
	if(start > end) return NULL;
	BSTNode* result = v[(start+end)/2];
	result->left = rebuildTree(v, 0, (start+end)/2-1);
	result->right = rebuildTree(v, (start+end)/2+1, v.size()-1);
	return result;
}

const int MAX_SUGGESTIONS = 3;
void suggestFriends(Map<string, Set<string> >& graph, Node *person){
	Set<string> friends = graph.get(person.name);
	Map<string, int> potentialFriends;
	foreach(string friend in friends){
		Set<string> friendsOfFriend = graph.get(friend);
		foreach(string acquintance in friendsOfFriend){
			if(anquintance != person.name && !friends.contains(acquintance)){
				potentialFriends[acquintance]++;
			}
		}
	}
	for(int i = 0; i < 3; i++)
		int max = -1;
		string newFriend;
		foreach(string newFriendz in potentialFriends){
			if(potentialFriends[newFriend] > max){
				newFriend = newFriendz;
				max = potentialFriends[newFriend];
			}
		}
		cout << newFriend << endl;
		cout << max << endl;
		potentialFriends.remove(newFriend);
	}
}







