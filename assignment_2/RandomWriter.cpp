/*
 * File: RandomWriter.cpp
 * ----------------------
 * Name: NINO CHIKVINIDZE
 * Section: 8
 * This file is the starter project for the Random Writer problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "map.h"
#include "vector.h"
#include "random.h"
#include <fstream>
#include <string>
using namespace std;

/* Initializing constants */
const int SEED_MIN_LENGTH = 1;
const int SEED_MAX_LENGTH = 10;
const int MAX_CHARS = 2000;

/* Prompts a user for a valid filename */
void openFile(ifstream &ifs) { 
	while (true) {
		string name = getLine("Enter the source text: ");
		ifs.open(name.c_str());
		if(ifs.fail()) {
			ifs.clear();
			cout << "Unable to open that file. Try again. " << endl;
		} else 
			break;
	}
}

/* Prompts the user to enter a valid length for Markov model */
int getLength() {
	int result = 0;
	while(true) {
		result = getInteger("Enter the Markov order [1-10]: ");
		if(result > SEED_MAX_LENGTH || result < SEED_MIN_LENGTH)
			cout << "That value is out of range." << endl;
		else 
			break;
	}
	return result;
}

/* Saves the last word of a file in a map */
void saveLast(Map<string, Vector<char> > &map, string currentSeed) {
	if(!map.containsKey(currentSeed)) 
		map.put(currentSeed, Vector<char> (0));
}

/* Saves the string and its successor character to a map */
void processString(Map<string, Vector<char> > &map, string seed, char ch) {
	if(!map.containsKey(seed)) {
		map.put(seed, Vector<char> (1, ch));
	} else {
		map[seed].add(ch);
	}
}

/* Gathers information on the frequencies of characters following a string */
Map<string, Vector<char> > processFile(ifstream &input, int length) {
	cout << "Processing file..." << endl;
	Map<string, Vector<char> > result;
	char ch;
	string currentSeed = "";
	while(input.get(ch)) {
		if(currentSeed.length() < length) {
			currentSeed += ch;
		} else {
			processString(result, currentSeed, ch);	
			currentSeed = currentSeed.substr(1, length-1) + ch;
		}
	}
	saveLast(result, currentSeed);
	return result;
}

/* Finds the length of the largest vector */
int maxLengthVec(Map<string, Vector<char> > &statistics) {
	int vectorSize = -1;
	foreach(string key in statistics) {
		if(statistics.get(key).size() > vectorSize) {
			vectorSize = statistics.get(key).size();
		}
	}
	return vectorSize;
}

/* Finds an initial seed based on statistics map, randomly chooses from most common occurances. */
string findInitialSeed(Map<string, Vector<char> > &statistics) {
	int vecSize = maxLengthVec(statistics);
	Vector<string> seeds;
	foreach(string key in statistics) {
		if(statistics.get(key).size() == vecSize)
			seeds.add(key);
	}
	int rand = randomInteger(0, seeds.size()-1);
	return seeds[rand];
}

/* Generates a random text based on the statistics of the frequencies */
void outputRandomText(Map<string, Vector<char> > &statistics) {
	string seed = findInitialSeed(statistics);
	cout << seed;
	int charCount = seed.length();
	char nextChar;
	while(charCount < MAX_CHARS) {
		int chooseFrom = statistics.get(seed).size();
		if(chooseFrom == 0)
			return;
		int rand = randomInteger(0, chooseFrom-1);
		nextChar = statistics.get(seed)[rand];
		cout << nextChar;
		seed = seed.substr(1) + nextChar;
		charCount++;
	}
}

/* Initializes an input file and makes a random text based on it */
int main() {
    ifstream input;
	openFile(input);
	int seedLength = getLength();
	Map<string, Vector<char> > statistics = processFile(input, seedLength);
	input.close();
	outputRandomText(statistics);
    return 0;
}
