/*
 * File: Subsequences.cpp
 * ----------------------
 * Name: NINO CHIKVINIDZE
 * Section: 8
 * This file is the starter project for the Subsequences problem
 * on Assignment #3.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include <string>
#include "console.h"
#include <string>
#include "simpio.h"
using namespace std;

/* Given two strings, returns whether the second string is a
 * subsequence of the first string.
 */
bool isSubsequence(string text, string subsequence){
	if(subsequence == "") return true;
	if(text == "") return false;
	if(subsequence[0] == text[0])
		return isSubsequence(text.substr(1), subsequence.substr(1));
	else 
		return isSubsequence(text.substr(1), subsequence);	
}

/* For checking if my recursive algorithm is correct */
int main() {
    string text = getLine();
	string sub = getLine();
	cout << isSubsequence(text, sub) << endl;
    return 0;
}
