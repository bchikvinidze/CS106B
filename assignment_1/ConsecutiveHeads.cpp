/*
 * File: ConsecutiveHeads.cpp
 * --------------------------
 * Name: NINO CHIKVINIDZE
 * Section: 8
 * This file is the starter project for the Consecutive Heads problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "console.h"
#include "random.h"
using namespace std;

const int N_OF_HEADS = 3;

/* 
	Uses recursion to  flip coins until the count of heads reaches N_OF_HEADS.
*/

int simulateFlipping(int countHeads) { 
	if(countHeads == N_OF_HEADS) return 0;
	if(randomChance(0.5)){
		cout << "heads" << endl;
		countHeads++;
	} else {
		cout << "tails" << endl;
		countHeads = 0;
	}
	return 1 + simulateFlipping(countHeads);
}

int main() {
    int flips = simulateFlipping(0);
	cout << "It took " << flips << " flips to get " << N_OF_HEADS << " consequtive heads." << endl;
    return 0;
}
