#pragma once

#include <iostream>
#include "console.h"
#include <string>
#include "simpio.h"
using namespace std;
const int START_SIZE = 2;

class TwoStackQueue
{
public:
	TwoStackQueue();
	~TwoStackQueue();
	void enqueue(int value); 
	int dequeue();
	int size(); 
	bool isEmpty(); 

private:
	int inLength;
	int outLength;
	int allocLength;
	int *arr;

};
