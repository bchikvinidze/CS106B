/*
 * File: WordLadder.cpp
 * --------------------------
 * Name: NINO CHIKVINIDZE
 * Section: 8
 * This file is the starter project for the Word Ladder problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "vector.h"
#include "queue.h"
#include "lexicon.h"
#include "set.h"
#include <string>
using namespace std;

/* prints out the words of the ladder */
void printLadder(Vector<string> &ladder) {
	if(ladder.size() == 0) {
		cout << "No word ladder could be found." << endl << endl;
	} else {
		cout << "Ladder found: ";
		for(int i = 0; i < ladder.size(); i++) {
			cout << ladder[i];
			if(i < ladder.size()-1) cout << " -> ";
		}
		cout << endl << endl;
	}
}

/* Adds a word to a ladder and adds this ladder in the queue
	of ladders, stores the word as already visited. */
void addWordLadder(string word, Set<string> &visited, 
				Queue<Vector<string> > &current, Vector<string> &next) {
	visited.add(word);
	Vector<string> temp = next;
	temp.add(word);
	current.enqueue(temp);
}

/* Searches the words to add in a ladder and fills a queue with possible ladders */
void findAndAdd(string nextWord, Lexicon lexicon, Queue<Vector<string> > &current,
				Set<string> &visited, Vector<string> &next, string end) {
	string word;
	for(int i = 0; i < nextWord.length(); i++) {
		word = nextWord;
		for(char ch = 'a'; ch <= 'z'; ch++) {
			word[i] = ch;
			if(!visited.contains(word) && lexicon.contains(word)) {
				addWordLadder(word, visited, current, next);
				if(word == end) 
					return;
			}
		}
	}
}

/* Uses breadth-first search algorithm to find the shortest ladder from start to end word */
Vector<string> findLadder(string start, string end, Lexicon lexicon) {
	Queue<Vector<string> > current;
	Set<string> visited;
	visited.add(start);
	current.enqueue(Vector<string> (1,start));
	while(!current.isEmpty()) {
		Vector<string> next = current.dequeue();
		string nextWord = next[next.size()-1];
		if(nextWord == end) return next;
		findAndAdd(nextWord, lexicon, current, visited, next, end);
	}
	return Vector<string> ();
}

/* Prompts a user to write start and end words for the word ladder and proceeds to find a ladder */
int main() {
	Lexicon english("EnglishWords.dat");
	string startWord;
	do {
		startWord = getLine("Enter the starting word (or nothing to quit): ");
		if(startWord == "") {
			cout << "Goodbye!" << endl;
		} else { 
			string endWord = getLine("Enter the ending word: ");
			cout << "Searching..." << endl;
			Vector<string> ladder = findLadder(startWord, endWord, english);
			printLadder(ladder);
		}
	} while (startWord != "");
    return 0;
}
