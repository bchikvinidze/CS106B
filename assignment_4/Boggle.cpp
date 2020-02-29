/*
 * File: Boggle.cpp
 * ----------------
 * Name: NINO CHIKVINIDZE
 * Section: 8
 * This file is the main starter file for Assignment #4, Boggle.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include "gboggle.h"
#include "grid.h"
#include "gwindow.h"
#include "lexicon.h"
#include "random.h"
#include "simpio.h"
using namespace std;

/* Constants */

const int BOGGLE_WINDOW_WIDTH = 650;
const int BOGGLE_WINDOW_HEIGHT = 350;
const int DIMENTION_ROW = 4;
const int DIMENTION_COL = 4;
const int MIN_WORD_SIZE = 4;
const int PAUSE_MILISECONDS = 360;

const string STANDARD_CUBES[16]  = {
    "AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS",
    "AOOTTW", "CIMOTU", "DEILRX", "DELRVY",
    "DISTTY", "EEGHNW", "EEINSU", "EHRTVW",
    "EIOSST", "ELRTTY", "HIMNQU", "HLNNRZ"
};
 
const string BIG_BOGGLE_CUBES[25]  = {
    "AAAFRS", "AAEEEE", "AAFIRS", "ADENNN", "AEEEEM",
    "AEEGMU", "AEGMNN", "AFIRSY", "BJKQXZ", "CCNSTW",
    "CEIILT", "CEILPT", "CEIPST", "DDLNOR", "DDHNOT",
    "DHHLOR", "DHLNOR", "EIIITT", "EMOTTT", "ENSSSU",
    "FIPRSY", "GORRVW", "HIPRRY", "NOOTUW", "OOOTTU"
};

/* Function prototypes */

void welcome();
void giveInstructions();
Grid<char> setupBoggle();
void shuffleCubes(Grid<char> &board);
Vector<string> arrayToVec();
void play(Lexicon &lexicon);
bool nextGame();

/* Main program */

int main() {
    GWindow gw(BOGGLE_WINDOW_WIDTH, BOGGLE_WINDOW_HEIGHT);
    initGBoggle(gw);
    welcome();
    giveInstructions();
	Lexicon english("EnglishWords.dat");
	bool playAgain;
	do {
		play(english);
		playAgain = nextGame();
	} while(playAgain);
	cout << "Goodbye." << endl;
    return 0;
}

/* Checks if the user wants to play again */
bool nextGame() {
	string playOrNot = getLine("Do you want to play again? ");
	if(playOrNot == "yes" || playOrNot == "YES")
		return true;
	return false;
}

/* Resets the used grid so that non of the letters are used */
void reset(Grid<bool> &usedGrid){
	for(int r = 0; r < usedGrid.nRows; r++)
		for(int c = 0; c < usedGrid.nCols; c++)
			usedGrid[r][c] = false;
}

/* Checks if the word can be found on the board */
bool findOnBoard(string word, Grid<char> &board, Grid<bool> &usedGrid, int row, int col) {
	if(word.size() == 0)
		return true;
	for(int r = -1; r <= 1; r++){
		for(int c = -1; c <= 1; c++) {
			if(board.inBounds(row+r, col+c) && !usedGrid[row+r][col+c] && 
				board[row+r][col+c] == word[0]){
					usedGrid[row+r][col+c] = true;
					if(findOnBoard(word.substr(1), board, usedGrid, row+r, col+c))
						return true;
					usedGrid[row+r][col+c] = false;
			}
		}
	}
	return false;
}

/* Highlights or removes highlight from visited letters on the board */
void highlightOrNot(Grid<bool> &usedGrid, bool invert){
	for(int i = 0; i < usedGrid.nRows; i++){
		for(int j = 0; j < usedGrid.nCols; j++)
			if(usedGrid[i][j]) highlightCube(i, j, invert);
	}
}

/* Checks if the word inserted by a human is more than a certain letters long,
	not used before and indeed a word on the board. */
bool check(string word, Lexicon &l, Set<string> &used, Grid<char> &board){
	if(word.size() >= MIN_WORD_SIZE && l.contains(word) && !used.contains(word)) {
		Grid<bool> usedGrid(board.nRows, board.nCols);
		for(int i = 0; i < board.nRows; i++){
			for(int j = 0; j < board.nCols; j++) {
				if(findOnBoard(word, board, usedGrid, i, j)){
					highlightOrNot(usedGrid, true);
					pause(PAUSE_MILISECONDS);
					highlightOrNot(usedGrid, false);
					return true;
				}
			}
		}
	}
	cout << "That word is invalid. " << endl;
	return false;
}

/* converts the given string to an uppercase version of itself */
string upperCaseWord(string word) {
	for( int i = 0; i < word.size(); i++ ) {
		if( word[i] >= 'a' && word[i] <= 'z')
			word[i] -= 32;
	}
	return word;
}

/* Lets the human play and concurrently renewes the score */
void humanTurn(Grid<char> &board, Lexicon &l, Set<string> &used){
	while(true) {
		string word = getLine("Enter a word (lower case): ");
		if(word == "") 
			break;
		word = upperCaseWord(word);
		if(check(word, l, used, board)){
			used.add(word);
			recordWordForPlayer(word, HUMAN);
		}
	}
}

/* Finds all the remaining words for the computer */
void findAllWords(string str, Grid<char> &board, Lexicon &l, 
					 Set<string> &used, Grid<bool> &usedGrid, int row, int col) {
	if(str.size() >= MIN_WORD_SIZE && !used.contains(str) && l.contains(str)){ // am bool-is gatana sheidzleba calke metodad.
		used.add(str);
		recordWordForPlayer(str, COMPUTER);
	}
	for(int r = -1; r <= 1; r++){
		for(int c = -1; c <= 1; c++) {
			if(board.inBounds(row+r, col+c) && !usedGrid[row+r][col+c] && 
				l.containsPrefix(str + board[row+r][col+c])){
					usedGrid[row+r][col+c] = true;
					findAllWords(str + board[row+r][col+c], board, l, used, usedGrid, row + r, col + c);
					usedGrid[row+r][col+c] = false;
			}
		}
	}
}

/* Lets the computer find the words that could not be
	found by the human player and calculates score
	accordingly */
void computerTurn(Grid<char> &board, Lexicon &l, Set<string> &used){
	Grid<bool> usedGrid(DIMENTION_ROW, DIMENTION_COL);
	string str = "";
	for(int i = 0; i < board.nRows; i++) {
		for(int j = 0; j < board.nCols; j++) {
			str = str + board[i][j];
			usedGrid[i][j] = true;
			findAllWords(str, board, l, used, usedGrid, i, j);
			usedGrid[i][j] = false;
			str = "";
		}
	}
}

/* Playing the game of Boggle by two players */
void play(Lexicon &english) {
	Grid<char> board = setupBoggle();
	Set<string> used;
	humanTurn(board, english, used);
	computerTurn(board, english, used);
}

/* Asks a user if manual configuration is wanted */
bool manualBoard() {
	string answ = getLine("Do you want manual configuration? ");
	if(answ == "yes" || answ == "YES") 
		return true;
	return false;
}

/* Lets the user define the board */
void userConfigBoard(Grid<char> &board) {
	string letters = getLine("Insert letters (no upper case): ");
	if(letters.size() < DIMENTION_ROW * DIMENTION_COL){
		userConfigBoard(board);
	} else {
		int index = 0;
		letters = toUpperCase(letters);
		for(int i = 0; i < DIMENTION_ROW; i++)
			for(int j = 0; j < DIMENTION_COL; j++)
				board[i][j] = letters[index++];
	}
}

/* Sets up the game of Boggle */
Grid<char> setupBoggle(){
	drawBoard(DIMENTION_ROW, DIMENTION_COL);
	Grid<char> board(DIMENTION_ROW, DIMENTION_COL);
	if(!manualBoard()) 
		shuffleCubes(board);
	else
		userConfigBoard(board);
	for(int row = 0; row < DIMENTION_ROW; row++){
		for(int col = 0; col < DIMENTION_COL; col++)
			labelCube(row, col, board[row][col]);
	}
	return board;
}

/* Swaps two values in a vector of strings. It's the same as moving cubes */
void swap(Vector<string> &letters, int index1, int index2) {
	string temp = letters[index1];
	letters[index1] = letters[index2];
	letters[index2] = temp;
}

/* Fills the board by random letters from a vector of cubes */
void fillGrid(Grid<char> &board, Vector<string> &letters) {
	for(int i = 0; i < board.nRows; i++) {
		for(int j = 0; j < board.nCols; j++)
			board[i][j] = letters[i+j][randomInteger(0, letters[i+j].size()-1)];
	}
}

/* Shuffles the cubes to display a letter */
void shuffleCubes(Grid<char> &board) {
	Vector<string> letters = arrayToVec();
	for(int i = 0; i < letters.size(); i++) {
		int index = randomInteger(i, letters.size()-1);
		swap(letters, i, index);
	}
	fillGrid(board, letters);
}

/* Converts an array to a vector */
Vector<string> arrayToVec(){
	Vector<string> result;
	for(int i = 0; i < DIMENTION_ROW * DIMENTION_COL; i++)
		result.add(STANDARD_CUBES[i]);
	return result;
}

/*
 * Function: welcome
 * Usage: welcome();
 * -----------------
 * Print out a cheery welcome message.
 */

void welcome() {
    cout << "Welcome!  You're about to play an intense game ";
    cout << "of mind-numbing Boggle.  The good news is that ";
    cout << "you might improve your vocabulary a bit.  The ";
    cout << "bad news is that you're probably going to lose ";
    cout << "miserably to this little dictionary-toting hunk ";
    cout << "of silicon.  If only YOU had a gig of RAM..." << endl << endl;
}

/*
 * Function: giveInstructions
 * Usage: giveInstructions();
 * --------------------------
 * Print out the instructions for the user.
 */

void giveInstructions() {
    cout << endl;
    cout << "The boggle board is a grid onto which I ";
    cout << "I will randomly distribute cubes. These ";
    cout << "6-sided cubes have letters rather than ";
    cout << "numbers on the faces, creating a grid of ";
    cout << "letters on which you try to form words. ";
    cout << "You go first, entering all the words you can ";
    cout << "find that are formed by tracing adjoining ";
    cout << "letters. Two letters adjoin if they are next ";
    cout << "to each other horizontally, vertically, or ";
    cout << "diagonally. A letter can only be used once ";
    cout << "in each word. Words must be at least four ";
    cout << "letters long and can be counted only once. ";
    cout << "You score points based on word length: a ";
    cout << "4-letter word is worth 1 point, 5-letters ";
    cout << "earn 2 points, and so on. After your puny ";
    cout << "brain is exhausted, I, the supercomputer, ";
    cout << "will find all the remaining words and double ";
    cout << "or triple your paltry score." << endl << endl;
    cout << "Hit return when you're ready...";
    getLine();
}