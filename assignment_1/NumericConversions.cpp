/*
 * File: NumericConversions.cpp
 * ---------------------------
 * Name: NINO CHIKVINIDZE
 * Section: 8
 * This file is the starter project for the Numeric Conversions problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
using namespace std;

/* Function prototypes */

string intToString(int n);
int stringToInt(string str);

/* Main program */

int main() {
	int num = getInteger("Write a number to convert to string: ");
	string numToString = intToString(num);
	int stringToNum = stringToInt(numToString);
	cout << "The string is: " << numToString << endl;
	cout << "The number, once again, is: " << stringToNum << endl;
    return 0;
}

/* recursively converts an integer to a string */

string intToString(int n) {
	if(n < 10 && n >= 0) return string() + char('0'+ n);
	if(n > 0) return intToString(n/10) + char('0' + n%10);
	if(n < 0) {
		n = -n;
		return "-" + (intToString(n/10) + char('0' + n%10));
	}
}

/* recursively converts a string to an integer. It is a given that a string will have length more than 0 and is
	convertible to integer. */

int stringToInt(string str) {
	if(str.length() == 1) return str[0] - '0';
	if(str[0] != '-') {
		return stringToInt(str.substr(0,str.length()-1)) * 10 + (str[str.length()-1] - '0');
	} else return -(stringToInt(str.substr(1,str.length()-2)) * 10 + (str[str.length()-1]) - '0');
}