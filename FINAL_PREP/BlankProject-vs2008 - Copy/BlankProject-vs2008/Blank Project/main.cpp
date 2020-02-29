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
#include "grid.h"
#include "TwoStackQueue.h"
#include "bstream.h"
#include "random.h"
using namespace std;

/* 
struct Box {
 int width;
 int height;
};

bool fitsAtR(int width, int height, int row, int col, const Grid<bool>& truck){  // motrialebuli 
	bool resultRotate = true;
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			if(!truck.inBounds(row+i, col+j) || truck[row+i][col+j]){
				resultRotate = false;
			}
		}
	}
	if(resultRotate == true)
		return true;
	return false;
}

bool fitsAtN(int width, int height, int row, int col, const Grid<bool>& truck){ // armotrialebuli
	bool resultNormal = true;
	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			if(!truck.inBounds(row+i, col+j) || truck[row+i][col+j]){
				resultNormal = false;
			}
		}
	}
	if(resultNormal == true)
		return true;
	return false;
}


bool canPlaceAll(int width, int height, Vector<Box>& boxes, Grid<bool>& truck){
	if(boxes.isEmpty()) return true;
	Box cur = boxes[boxes.size()-1];
	boxes.remove(boxes.size()-1);
	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			if(fitsAtN(cur.width, cur.height, i, j, truck)){
				for(int a = 0; a < cur.width; a++){//dadeba
					for(int b = 0; b < cur.height; b++){
						truck[i+a][j+b] = true;
					}
				}
				if(canPlaceAll(width, height, boxes, truck))
					return true;
				for(int a = 0; a < cur.width; a++){//ageba
					for(int b = 0; b < cur.height; b++){
						truck[i+a][j+b] = false;
					}
				}
			} 
			if(fitsAtR(cur.width, cur.height, i, j, truck)){
				for(int a = 0; a < cur.height; a++){//dadeba
					for(int b = 0; b < cur.width; b++){
						truck[i+a][j+b] = true;
					}
				}
				if(canPlaceAll(width, height, boxes, truck))
					return true;
				for(int a = 0; a < cur.width; a++){//ageba
					for(int b = 0; b < cur.height; b++){
						truck[i+a][j+b] = false;
					}
				}
			}
		}
	}
	return false;
}

bool canPlaceAllBoxes(int width, int height, Vector<Box>& boxes){
	Grid<bool> truck(height, width);
	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			truck[i][j] = false;
		}
	}
	return canPlaceAll(width, height, boxes, truck);
}


int main(){
	int width = 8;
	int height = 5;
	Vector<Box> boxes;
	Box b1;
	Box b2;
	Box b3;
	Box b4;
	Box b5;
	b1.width = 3;
	b1.height = 2;
	b2.width = 2;
	b2.height = 3;
	b3.width = 3;
	b3.height = 2;
	b4.width = 6;
	b4.height = 2;
	b5.width = 2;
	b5.height = 3;
	boxes.add(b1);
	boxes.add(b2);
	boxes.add(b3);
	boxes.add(b4);
	boxes.add(b5);
	cout << canPlaceAllBoxes(width, height, boxes) << endl;
	return 0;
} */

/* TwoStackQueue 
int main(){
	TwoStackQueue stackQ;
	int a = getInteger();
	int b = getInteger();
	int c = getInteger();
	int d = getInteger();
	int e = getInteger();
	stackQ.enqueue(a);
	stackQ.enqueue(b);
	stackQ.enqueue(c);
	stackQ.enqueue(d);
	stackQ.enqueue(e);
	cout << stackQ.dequeue() << endl;
	cout << stackQ.dequeue() << endl;

	return 0;
} */

/* 
struct Node {
	Node* left;
	Node* right;
};

void compressTree(Node* root, string &out){
	if(root == NULL){
		out += '0';
		return;
	}
	out += '1';
	compressTree(root->left);
	compressTree(root->right);
} 

Node* decompress(string &in){
	if(in.size() <= 1){
		return NULL;
	}
	if(in[0] == '0'){
		return NULL;
	}
	Node* newNode = new Node;
	newNode->left = decompress(in);
	newNode->right = decompress(in);
	return newNode;
}

Node* decompressTree(string &in){
	return decompress(in, NULL);
}
*/


/* AMOCANA GRAFEBZEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
void reverse(Map<string, Set<string> > g){
	Map<string, Set<string> > result;
	for(int i = 0; i < g.size(); i++){
		foreach(string city in g.keys()[i]){
			if(result.containsKey(city)){
				Set<string> s = result.get(city);
				s.add(g.keys()[i]);
				result.put(city, s);
			} else {
				Set<string> s;
				s.add(g.keys()[i]);
				result.put(city, s);
			}
		}
	}
	return result;
}

void depthFirst(Map<string, Set<string> >& g, Set<string>& visited, string city){
	if(visited.contains(city)) return;
	visited.add(city);
	foreach(string neighbor in g.get(city)){
		if(!visited.contains(neighbor)){
			depthFirst(g, visited, city);
		}
	}	
}

bool isGoodNetwork(Map<string, Set<string> >& g){
	Vector<string> all = g.keys();
	Set<string> visited;
	depthFirst(g, visited, all[0]);
	for(int i = 0; i < all.size(); i++){
		if(!visited.contains(all[i]))
			return false;
	}
	return true;
}

bool isNetwork(Map<string, Set<string> >& g){
	bool r1 = isGoodNetwork(g);
	if(r1){
		Map<string, Set<string> > g2 = reverse(g);
		return isGoodNetwork(g2);
	}
	return false;
}
*/

/* CHVENI PIRVELI DA MEORE AMOCANEBIIII
struct Node{
	int value;
	Node* left;
	Node* right;
};

void recW(Node* root, int k, Vector<int> &res){
	if(root == NULL) return;
	if(k == 0){
		result.add(root->value());
		return;
	}
	k -= 1;
	recW(root->left, k, res);
	recW(root->right, k, res);
}

Vector<int> rec(Node* root, int k){
	Vector<int> result;
	recW(root, k, result);
	return result;
}	

int calcDepth(Node* root, int& result){
	if(root == NULL)
		return 0;
	int depth1 = 1+ calcDepth(root->left);
	int depth2 = 1+ calcDepth(root->right);
	if(depth1 > depth2) return depth1;
	return depth2;
}

int width(Node* root){ 
	int maxWidth = 0; 
	int d = 0;
	int depth = calcDepth(root, d);
	for(int i = 0; i < depth; i++){
		Vector<int> vec = rec(root, i);
		if(vec.size() > maxWidth)
			maxWidth = vec.size();
	}
	return maxWidth;
} */

// aqdan iwyeba 270 CS106B-s amoxsnebi
//
//
//
//
//
////
//
////
//
////
//
////
//
////
//
//


/* First problem in 270 Cs106B
string winnerOf(string p1, string p2){ // amis dawerac chemit miwevs
	bool rand = randomChance(0.5);
	if(rand) 
		return  p1;
	return p2;
}

string overallWinnerOf(Vector<string>& initialOrder){
	if(initialOrder.size() == 1)
		return initialOrder[0];
	Vector<string> winners;
	for(int i = 0; i < initialOrder.size(); i += 2){
		winners.add(winnerOf(initialOrder[i], initialOrder[i+1]));
	}
	return overallWinnerOf(winners);
}

bool canRigFor(string& player, Set<string>& allPlayers,
			   Vector<string>& initialOrder){
	if(overallWinnerOf(initialOrder) == player)
		return true;
	for(int i = 0; i < allPlayers.size(); i++){
		for(int j = 0; j < allPlayers.size() - 1; j++){
			if(i != j){
				string otherPl = initialOrder[i];
				string thisPl = initialOrder[j];
				initialOrder[i] = thisPl;
				initialOrder[j] = otherPl;
				if(canRigFor(player, allPlayers, initialOrder))
					return true;
				initialOrder[i] = otherPl;
				initialOrder[j] = thisPl;
			}
		}	
	}
	return false;
}

bool canRigFor(string& player, Set<string>& allPlayers,
			   Vector<string>& initialOrder){
	if(allPlayers.isEmpty()){
		if(overallWinnerOf(initialOrder) == player)
			return true;
		return false;
	}
	foreach(string opponent in allPlayers){
		initialOrder.add(opponent);
		allPlayers.remove(opponent);
		if(canRigFor(player, allPlayers, initialOrder)) return true;
		allPlayers.add(opponent);
	}
	return false;
} */


/* Fouth problem from 270 CS106B
struct Node {
	double value; // The value stored in this node
	Node* left; // Standard left and right child pointers
	Node* right;
};

void wrapper(Node* root, Set<double>& set){
	if(root == NULL)
		return;
	if(root->left == NULL){
		set.add(root->value);
	} else {
		wrapper(root->left, set);
		wrapper(root->right, set);
	}
}

Set<double> leavesOf(Node* root) {
	Set<double> set;
	wrapper(root, set);
}

double distance(double a, double b){
	if(a-b > 0) return a-b;
	return b-a;
}

void rec(int numClusters, Set<Node*>& result){
	if(result.size() == numClusters)
		return;
	Node* n1;
	Node* n2;
	double dist = 9999999;
	foreach(Node* node1 in result){
		foreach(Node* node2 in result){
			if(node1 != node2){
				if(distance(node1->value, node2->value) < dist){
					n1 = node1;
					n2 = node2;
					dist = distance(node1->value, node2->value);
				}
			}
		}
	} // napovni gvaq romeli ori unda gavaertianot
	Node* newRoot = new Node;
	newRoot->left = n1;
	newRoot->right = n2;
	Set<double> leaves1 = leavesOf(n1);
	Set<double> leaves2 = leavesOf(n2);
	int sum = 0;
	foreach(double val in leaves1)
		sum += val;
	foreach(double val in leaves2)
		sum += val;
	sum = sum/(leaves1.size() + leaves2.size());
	newRoot->value = sum;
	result.remove(n1);
	result.remove(n2);
	result.add(newRoot);
	rec(numClusters, result);
}

Set<Node*> cluster(Set<double>& values, int numClusters){
	Set<Node*> result;
	int size = values.size()
	for(int i = 0; i < size; i++){
		Node* newNode = new Node;
		newNode->value = values.first();
		values.remove(values.first());
		newNode->left = NULL;
		newNode->right = NULL;
		result.add(newNode);
	}
	rec(numClusters, result);
	return result;
} */

/*
Map<string, int> distancesFrom(const string& start, const Graph& graph) {
	Queue<Path> worklist;
	worklist.enqueue({ start });
	Set<string> visited = { start };
	Map<string, int> result;
	result[start] = 0;
	while (!worklist.isEmpty()) {
		Path path = worklist.dequeue();
		string last = path[path.size() - 1];
		for (string next: graph[last]) {
			if (!visited.contains(next)) {
				visited.add(next);
				result[next] = Path.size();
				Path nextPath = path;
				nextPath += next;
				worklist.enqueue(nextPath);
			}
		}
	}
	return result;
}

using Graph = Map<string, Set<string>>;
using Path = Vector<string>;
/* Assume this function works properly. */ /*
Map<string, int> distancesFrom(string& start, Graph& graph);
Vector<Path> allShortestPathsBetween(string& start, string& end,
												 Graph& graph) {
	Map<string, int> allDistances = distancesFrom(start, graph);
	Vector<Path> result;
	rec(end, start, graph, distances, result, { end });
	return result;
}

void rec(string& end, string& start, Graph& graph,  Map<string, int>& distances, 
		 Vector<Path>& result, Path& soFar){
	
} */

// AQEDAN IWYEBA SECTION HANDOUT 8-s AMOXSNEBI< JAFARAS GAMOGZAVNILIS!!!!!!!
// gvaqvs:
/* OurHashSet klasi. private cvladebi:
Vector<Vector<std::string>> buckets;
int numElems;
*/
//void OurHashSet::add(const string& value) {
//	/* Determine the bucket to jump into. */
//	int bucket = hashCode(value) % buckets.size();
//	/* If this element is already present, we don't need to do anything. */
//	for (string elem: buckets[bucket]) {
//		if (elem == value) return;
//	}
//	buckets[bucket] += value;
//	numElems++;
//	if(numElems/buckets.size() >= 2)
//		rehash();
//}
//
//void OurHashSet::rehash(){
//	Vector<Vector<string> > bucketsNew(buckets.size()*2);
//}
//
//// faili final exam < 2011 wlis dzveli ragacaa, gaketebad girs.
//int FillKnapsack(Vector<objectT> objects, int targetWeight){
//	return fill(objects, targetWeight, 0);
//}
//
//int fill(Vector<objectT> objects, int targetWeight, int value){
//	if(targetWeight < 0) // ar chaetia :(
//		return 0;
//	int max = value;
//	for(int i = 0; i < objects.size(); i++){
//		objectT choose = objects[objects.size()-1];
//		objects.remove(objects.size()-1);
//		int newMax = fill(objects, targetWeight - choose.weight, value+choose.value);
//		int newMax2 = fill(objects, targetWeight, value);
//		max = max(newMax, newMax2);
//	}
//	return max;
//}
struct Node {
	int val;
	NodeT* left;
	NodeT* right;
};

void printTree(Node* root){ // seminari 27 - pirvelive amocana!
	while(root != NULL){
		cout << min(root)->val << endl;
		remove(min(root));
		cout << max(root)->val << endl;
		remove(max(root));
	}
}



















int cube(int num) {
	return num * num * num;
}

bool idealCube(int n, Set<int>& cubes){
//ogondaca raaa	
}

struct treeT {
	char value;
	treeT * left;
	treeT * right;
};

void BuildAll(Vector<char> &sortedValues, Set<treeT*> &bsts, treeT* treeSoFar){
	
}

Set<treeT *> BuildAllBSTs (Vector<char> & sortedValues) {
	Set<treeT*> bsts;
	BuildAll(sortedValues,bsts,NULL);
	return bsts;
}

















struct arcT {
	string name;
	nodeT * a;
	nodeT * b;
};

struct nodeT {
	Set<arcT *> arcs;
};

void PrintAllBridges(Set<nodeT *> & allNodes, Set<arcT *> & allArcs) {
	int cur = numComponents(allNodes, allArcs);
	foreach(arcT* arc in allArcs){
		allArcs.remove(arc);
		int newCur = PrintAllBridges(allNodes, allArcs);
		if(newCur > cur){
			cout << arc.name << endl;
		}
		allArcs.add(arc);
	}
}

int numComponents(Set<nodeT *> & allNodes, Set<arcT *> & allArcs) {
	int components = 0;
	Set<nodeT *> visited;
	Queue<nodeT *> q;
	foreach(nodeT* node in allNodes){
		if (!visited.contains(node)) {
			components++;
			q.enqueue(node);
			visited.insert(node);
			while (!q.isEmpty()) {
				nodeT * curNode = q.dequeue();
				foreach(arcT* neighbour in curNode->arcs) {
					if (!visited.contains(neighbour->a)) {
						q.enqueue(a);
						visited.insert(a);
					}
					if (!visited.contains(neighbour->b)) {
						q.enqueue(b);
						visited.insert(b);
					}
				}
			}
		}
	}
	return components;
}




void breadthFirstSearch(Node* root){
	Queue<Node*> q;
	q.enqueue(root);
	while(!q.isEmpty()){
		Node* cur = q.dequeue();
		if(cur == NULL) 
			continue;
		cout << cur->val << endl;
		breadthFirstSearch(root->left);
		breadthFirstSearch(root->right);
	}
}

Set<string> winnersOf(Map<string, Set<string>>& tournament){
	Set<string> winners;
	foreach(string player in tournament){
		Set<string> oneHop = tournament[players]; // vis mougo pirvelive hop-ze
		Set<string> twoHops;
		foreach(string otherPlayer in oneHop){
			twoHops.add(otherPlayer);
		}
	}	
}

Map<string, Set<string> > subTournament(Set<string>& players, Map<string, Set<string>>& tournament){
	Map<string, Set<string> > result;
	foreach(string player in players){
		result[player] = tournament[player]*players;
	}
	return result;
}

Vector<string> victoryChainFor(Map<string, Set<string>>& tournament){
	if(tournament.size() == 0)
		return {};
	Set<string> playerz;
	foreach(string pl in tournament)
		playerz.add(pl);
	string curPlayer = playerz.first();
	Set<string> wonOver = tournament.get(curPlayer);
	Set<string> couldntWinOver = playerz - curPlayer - wonOver;
	Vector<string> result = victoryChainFor(subTournament(couldntWinOver, tournament));
	result.add(curPlayer);
	result += victoryChainFor(subTournament(wonOver, tournament));
	return result;
}

int distance(string start, string end, Map<string, Set<string>>& graph){
	int dist = 0;
	Queue<sting> q;
	Set<string> visited;
	q.enqueue(start);
	visited.add(start);
	while(!q.isEmpty()){
		string cur = q.dequeue();
		dist++;
		foreach(string neighbor in graph[cur]){
			if(neighbor == end)
				return dist;
			q.add(neighbor);
		}
	}
	return -1; //ver vipovet kavshiriiiiiiii :((
}

int eccentricityOf(Map<string, Set<string>>& graph, string& node){
	int max = -1;
	foreach(string otherNode in graph){
		if(distance(node, otherNode, graph) > max)
			max = distance(node, otherNode, graph);
	}
	return max;
}

Set<int> maxSumSubset (treenode * root){
	Set<int> result;
	int depthLeft = calculateDepth(root->left);
	int depthRight = calculateDepth(root->right);
	Vector
	for(int i = 0; i < depthLeft; i++){
		
	}
	for(int j = 0; j < depthRight; j++){
		
	}
	return result;
}



struct listnode {
	int val;
	listnode * next;
};

bool contains(listnode * list, listnode * sub) {
	if(sub == NULL)
		return true;
	if(list == NULL)
		return false;
	if(list->val == sub->val)
		return contains(list->next, sub->next);
	return contains(list->next, sub);
}

void largestTreeforV(Map<Vertex*, Set<Vertex*>& graph, int& size, Vertex*& largestForV, Set<Vertex*>& visited){
	if(largestForV == NULL) return;
	if(!visited.contains(largestForV)){
		visited.add(largestForV);
		foreach(Vertex* neighbor in graph[largestForV]{
			size++;
			largestTreeForV(graph, size, neighbor, visited);

		} 
	} else 
		size = 0;
}

Vertex* findLargestTree(Map<Vertex*, Set<Vertex*>& graph) {
	int largest = 0;
	Vertex* result;
	foreach(Vertex* v in graph){// am v-dan dawyebuli tree
		int size = 0;
		Vertex* largestForV = v;
		Set<Vertex*> visited;
		largestTreefor(graph, size, largestForV, visited);
		if(size > largest){
			largest = size;
			result = largestForV;
		}
	}
	return result;
}

Struct NodeT{
	int val;
	NodeT * left;
	NodeT * right;
};

void print(NodeT* head, NodeT*& root){
	if(head == NULL)
		return;
	print(head->left, root); // ar imushavaaaaaaaaa ddshvc
	cout << head->val << endl;
	delete head->left;
	head = root;
	print(head->right, root);
	cout << head->right << endl;
	delete head->right;
	head = root;
	print(head, root);
}

void printTree(NodeT * head){
	print(head, head);
}

void countThis(int n, int &count, int[]a){
	if(n == 1){
		count++;
		return;
	}
	if(n < 1)
		return;
	for(int i = 0; i < a.size(); i++){
		if(n % a[i] == 0){
			countThis(n/a[i], count, a);
		}  
		countThis(n-1, count, a);
	}
}

int PathCount(int n, int[]a){
	int count = 0;
	countThis(n, count, a);
	return count;
}




























































































