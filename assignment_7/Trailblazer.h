/******************************************************************************
 * File: Trailblazer.h
 *
 * Exports functions that use Dijkstra's algorithm, A* search, and Kruskal's
 * algorithm as specified in the assignment handout.
 */

#ifndef Trailblazer_Included
#define Trailblazer_Included

#include "TrailblazerTypes.h"
#include "TrailblazerPQueue.h"
#include "set.h"
#include "grid.h"

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
 * search.  Make sure to update both this function prototype and the
 * implementation inside of Trailblazer.cpp.
 */
Vector<Loc>
shortestPath(Loc start,
             Loc end,
             Grid<double>& world,
             double costFn(Loc from, Loc to, Grid<double>& world), 
			 double heuristic(Loc start, Loc end, Grid<double>& world));

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
Set<Edge> createMaze(int numRows, int numCols);

/* copies the shortest path (technically already found implicitely) to the 
 * vector of Locs
 */
void findPath(Vector<Loc> &result, Grid<Loc> &parents, Loc start, Loc end);

/* Sets color of a location for Dijskrtra and A* algorithms */
void setColor(Grid<double>& world, Loc &loc, Color color, Grid<Color>& colors);

/* Checks the neighboring locations for Dijsktra and A* algorithms */
void checkNeighbors(Grid<double>& world, Loc& cur, Loc &end, Grid<Color>& colors,
					Grid<double>& dist, Grid<Loc>& parents, 
					TrailblazerPQueue<Loc>& tpq, 
					double costFn(Loc from, Loc to, Grid<double>& world), 
					double heuristic(Loc start, Loc end, Grid<double>& world));

/* Assigns each edge on the grid a random weight */
void assignWeights(TrailblazerPQueue<Edge> &tpq, Vector<int> &clusterz,
				   int numRows, int numCols);

/* Part of the Union-Find algorithm: This functions sets up a vector of clusters
 * for each location on the map. At first, every location is a root of itself.
 */
void setupUnionFind(Vector<int>& clusters);

/* Part of the Union-Find algorithm: Finds the Root of a parameter n in the vector of clusters.
 * According to the Find part of the Union-Find algorithm, we first find which cluster a number n
 * belongs to by tracing down the vector of clusters until we find a member of the vector which is 
 * a root of itself. 
 */ 
int findRoot(Vector<int>& clusters, int n);

/* Part of the Union-Find algorithm. Union operation (unionOp for short) is used to merge two
 * clusters together. It takes two locations as parameters, identifies which number of the vector
 * represents them (row and column numbers are used to make this calculation) and makes the root
 * of one of the locations as a root of the other location.  
 */ 
void unionOp(Vector<int>& clusters, Loc l1, Loc l2, int numCols);

#endif
