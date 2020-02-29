/*
 * File: Combinations.cpp
 * ----------------------
 * Name: BUBU CHIKVINIDZE
 * Section: 8
 * This file is the starter project for the Combinations problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
using namespace std;

/* uses simple recursion to return the combination of two non-negative whole numbers, n and k. */

int combinations(int n, int k) {
	if(k == 0 || n == k) return 1;
	return combinations(n-1, k-1) + combinations(n-1, k);
}

int main() {
	int n = getInteger("Write the first number: "); 
	int k = getInteger("Write the second number: ");
	if(n >= k && n >= 0 && k >= 0){
		cout << "Combination returnes the following result: " << combinations(n,k) << endl;
	} else cout << "This combination is not defined." << endl;
    return 0;
}
