/*
 * File: FleschKincaid.cpp
 * ----------------------
 * Name: NINO CHIKVINIDZE
 * Section: 8
 * This file is the starter project for the Flesch-Kincaid problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "tokenscanner.h"
#include <fstream>
#include <cctype> 
#include "strlib.h"
using namespace std;

/* Constants */
const double C0 = -15.59;
const double C1 = 0.39;
const double C2 = 11.8;

/* Prompts a user for a valid filename until a valid filename is written */
void openFile(ifstream &ifs) { 
	while (true) {
		string name = getLine("Enter file name: ");
		ifs.open(name.c_str());
		if(ifs.fail()) {
			ifs.clear();
			cout << "enter name again. " << endl;
		} else 
			break;
	}
}

/* information that should be kept about a token. */
struct tokenInfo{
	string type;
	int syllables;
};

/* checks if a token is a word */
bool isWord(string token) {
	if(isalpha(token[0])) return true;
	return false;
}

/* checks if a letter is a vowel */
bool isVowel(char ch) {
	if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') return true;
	return false;
}

/* counts syllables */
int countSyllables(string token) {
	int syllables = 0;
	token = toLowerCase(token);
	for(int i = 0; i < token.length(); i++) 
		if(isVowel(token[i]) && !(i == token.length() - 1 && token[i] == 'e')) 
			if(i == 0 || (i>0 && !isVowel(token[i-1]))) 
				syllables++;
	if(syllables == 0) syllables++;
	return syllables;
}

/* Assigning values to the information about a token. */
tokenInfo info(string token){
	tokenInfo result;
	if(token == "." || token == "!" || token == "?") {
		result.type = "(end of sentence)";
		result.syllables = 0;
	} else if(isWord(token)) {
			result.type = "word";
			result.syllables = countSyllables(token);
	} else {
		result.type = "";
		result.syllables = 0;
	}
	return result;
}

/* Variables of the formula */
struct Variables{
	int words;
	int sentences;
	int syllables;
	Variables(int words, int sentences, int syllables) {
		this->words = words;
		this->sentences = sentences;
		this->syllables = syllables;
	}	
};

/* initializing TokenScanner */
TokenScanner tokScan(ifstream &ifs) {
	TokenScanner scanner(ifs);
	scanner.ignoreWhitespace();
	scanner.addWordCharacters("'");
	//scanner.addWordCharacters("-"); //such logic is not needed apparently, so I commented it.
	return scanner;
}

/* shows if the user wants to view debug */
bool promptDebug(string str) {
	if(str == "YES" || str == "yes") return true;
	if(str == "NO" || str == "no") return false;
	return promptDebug(getLine("Yes or no answers only: "));
}

/* debugging the text */
void showDebug(string token) {
	cout << "Token: [" + token + "]";
	if(info(token).type.find("word") != string::npos) 
		cout << info(token).type + "; " << info(token).syllables << " syllables. ";
	else if(info(token).type.find("sentence") != string::npos) cout << info(token).type;
	cout << endl;
}

/* Reading and debugging text, token by token, while calculating Variables for the formula */
Variables readFile(ifstream &ifs) {
	Variables var(0,0,0);
	TokenScanner scanner = tokScan(ifs);
	bool debug = promptDebug(getLine("Show Debug Information? Yes/No: "));
	while(scanner.hasMoreTokens()) {
		string token = scanner.nextToken();
		if(debug) showDebug(token);
		if(info(token).type.find("word") != string::npos) {
			var.words++;
			var.syllables += info(token).syllables;
		} else if(info(token).type.find("sentence") != string::npos) {
			var.sentences++;
		} 
	}
	return var;
}

void calculateGrade(Variables var) {
	cout << "Words: " << var.words << endl
		 << "Syllables: " << var.syllables << endl
		 << "Sentences: " << var.sentences << endl;
	if(var.sentences != 0 && var.words != 0) 
		cout << "Grade level: " << C0+C1*var.words/var.sentences+C2*var.syllables/var.words << endl;
}

int main() {
    ifstream ifs;
	openFile(ifs);
	Variables var = readFile(ifs);
	calculateGrade(var);
    return 0;
}
