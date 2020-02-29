/******************************************************************************
 * File: Trailblazer.cpp
 *
 * Implementation of the graph algorithms that comprise the Trailblazer
 * assignment.
 */

#include "Trailblazer.h"
#include "TrailblazerGraphics.h"
#include "TrailblazerTypes.h"
#include "TrailblazerPQueue.h"
#include "grid.h"
#include "map.h"
#include "random.h"
using namespace std;

/* Declaring constants */
const double MIN_WEIGHT = 0;
const double MAX_WEIGHT = 9;
const int NEIGHBOR_COUNT = 4;
// This matrix is used to find the neighboring locations of current location in a maze.
const int neighborMatrix[NEIGHBOR_COUNT][2] = { {-1, 0}, {1, 0}, {0, 1}, {0 ,-1} };

/* Function: shortestPath
 * 
 * Finds the shortest path between the locations given by start and end in the
 * specified world.	 The cost of moving from one edge to the next is specified
 * by the given cost function.	The resulting path is then returned as a
 * Vector<Loc> containing the locations to visit in the order in which they
 * would be visited.	If no path is found, this function should report an
 * error.
 *
 * In Part Two of this assignment, you will need to add an additional parameter
 * to this function that represents the heuristic to use while performing the
 * search.  Make sure to update both this implementation prototype and the
 * function prototype in Trailblazer.h.
 */
Vector<Loc>
shortestPath(Loc start,
             Loc end,
             Grid<double>& world,
             double costFn(Loc from, Loc to, Grid<double>& world), 
			 double heuristic(Loc start, Loc end, Grid<double>& world)) {
	Vector<Loc> result;
	TrailblazerPQueue<Loc> tpq;
	// The following three grids are to be used  for storing distances, colors and parents for each loction:
	Grid<double> dist(world.nRows, world.nCols); // distances from the starting node.
	Grid<Color> colors(world.nRows, world.nCols); // colors of each Loc.
	Grid<Loc> parents(world.nRows, world.nCols); // parent for each Loc.
	setColor(world, start, YELLOW, colors);
	dist[start.row][start.col] = 0;
	tpq.enqueue(start, heuristic(start, end, world));
	while(!tpq.isEmpty()){
		Loc cur = tpq.dequeueMin();
		setColor(world, cur, GREEN, colors);
		if(cur == end) {
			findPath(result, parents, cur, start);
			break;
		}
		checkNeighbors(world, cur, end, colors, dist,
			parents, tpq, costFn, heuristic);
	}
	return result;
}

/* Function: createMaze
 * 
 * Creates a maze of the specified dimensions using a randomized version of
 * Kruskal's algorithm, then returns a set of all of the edges in the maze.
 *
 * As specified in the assignment handout, the edges you should return here
 * represent the connections between locations in the graph that are passable.
 * Our provided starter code will then use these edges to build up a Grid
 * representation of the maze.
 */
Set<Edge> createMaze(int numRows, int numCols) {
	Set<Edge> result;
	TrailblazerPQueue<Edge> tpq;
	Vector<int> clusterz(numRows*numCols);
	setupUnionFind(clusterz);
	assignWeights(tpq, clusterz, numRows, numCols);
	while(!tpq.isEmpty()){
		Edge e = tpq.dequeueMin();
		int cluster = findRoot(clusterz, e.end.row * numCols + e.end.col);
		if(findRoot(clusterz, e.start.row * numCols + e.start.col) != cluster){
			unionOp(clusterz, e.start, e.end, numCols);
			result.add(e);
		}
	}
	return result;
}

/* Sets color of a location for Dijskrtra and A* algorithms */
void setColor(Grid<double>& world, Loc &loc, Color color, Grid<Color>& colors){
	colorCell(world, loc, color);
	colors[loc.row][loc.col] = color;
}

/* Checks the neighboring locations for Dijsktra and A* algorithms */
void checkNeighbors(Grid<double>& world, Loc& cur, Loc &end, Grid<Color>& colors,
					Grid<double>& dist, Grid<Loc>& parents, 
					TrailblazerPQueue<Loc>& tpq, 
					double costFn(Loc from, Loc to, Grid<double>& world), 
					double heuristic(Loc start, Loc end, Grid<double>& world)){
	for(int i = -1; i <= 1; i++){
		for(int j = -1; j <= 1; j++){
			if(world.inBounds(cur.row+i, cur.col+j) && !(i == 0 && j == 0)){
				Loc v = makeLoc(cur.row + i, cur.col + j);
				double cost = costFn(cur, v, world);
				if(colors[v.row][v.col] == GRAY){
					setColor(world, v, YELLOW, colors);
					dist[v.row][v.col] = dist[cur.row][cur.col] + cost;
					parents[v.row][v.col] = cur;
					tpq.enqueue(v, dist[v.row][v.col] + heuristic(v, end, world));
				} else if(colors[v.row][v.col] == YELLOW && 
					dist[v.row][v.col] > dist[cur.row][cur.col] + cost){
					dist[v.row][v.col] = dist[cur.row][cur.col] + cost;
					parents[v.row][v.col] = cur;
					tpq.decreaseKey(v, dist[v.row][v.col] + heuristic(v, end, world));
				}
			}
		}
	}
}

/* copies the shortest path (technically already found implicitly) to the 
 * vector of Locs
 */
void findPath(Vector<Loc> &result, Grid<Loc> &parents, Loc start, Loc end){
	result.add(start);
	if(start == end)
		return;
	findPath(result, parents, parents[start.row][start.col], end);
}

/* Assigns each edge on the grid a random weight */
void assignWeights(TrailblazerPQueue<Edge> &tpq, Vector<int> &clusters, 
				   int numRows, int numCols){
	Set<Edge> covered;
	foreach(int start in clusters){
		for(int i = 0; i < NEIGHBOR_COUNT; i++){
			Loc neighbor = makeLoc(start/numRows + neighborMatrix[i][0], start % numRows + neighborMatrix[i][1]);
			if(neighbor.row >= 0 && neighbor.row < numRows &&
				neighbor.col >= 0  && neighbor.col < numCols){
				Edge e;
				e.start = makeLoc(start/numRows, start % numRows);
				e.end = neighbor;
				Edge reverse;
				reverse.start = e.end;
				reverse.end = e.start;
				if(!covered.contains(reverse)){
					tpq.enqueue(e, double(randomInteger(MIN_WEIGHT, MAX_WEIGHT)));
					covered.add(e);
					covered.add(reverse);
				}
			}
		}
	}
}

/* Part of the Union-Find algorithm: This functions sets up a vector of clusters
 * for each location on the map. At first, every location is a root of itself.
 */
void setupUnionFind(Vector<int>& clusters){
	for(int i = 0; i < clusters.size(); i++){
		clusters[i] = i; 
	}
}

/* Part of the Union-Find algorithm: Finds the Root of a parameter n in the vector of clusters.
 * According to the Find part of the Union-Find algorithm, we first find which cluster a number n
 * belongs to by tracing down the vector of clusters until we find a member of the vector which is 
 * a root of itself. 
 */ 
int findRoot(Vector<int>& clusters, int n){
	while(n != clusters[n])
		n = clusters[n];
	return n;
}

/* Part of the Union-Find algorithm. Union operation (unionOp for short) is used to merge two
 * clusters together. It takes two locations as parameters, identifies which number of the vector
 * represents them (row and column numbers are used to make this calculation) and makes the root
 * of one of the locations as a root of the other location.  
 */ 
void unionOp(Vector<int>& clusters, Loc l1, Loc l2, int numCols){
	int n1 = l1.row * numCols + l1.col;
	int n2 = l2.row * numCols + l2.col;
	int root1 = findRoot(clusters, n1);
	int root2 = findRoot(clusters, n2);
	clusters[root1] = root2;
}