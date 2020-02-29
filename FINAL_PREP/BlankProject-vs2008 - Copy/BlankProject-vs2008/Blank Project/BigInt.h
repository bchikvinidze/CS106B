#pragma once

#include <string>
using namespace std;
class BigInt
{
public:
	BigInt(string number);
	~BigInt();
	string toString();
private:
	struct Node{
		int value;
		Node* next;
	};
	bool isNegative;
	Node* head;
};
