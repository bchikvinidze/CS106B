#pragma once
#include <string>

class MoveToFrontSet
{
public:
	MoveToFrontSet(); // Creates an empty set
	~MoveToFrontSet(); // Cleans up all memory allocated
	bool contains(const string& str); // Returns whether str is present.
	void add(const string& str); // Adds str if it doesn’t already exist.
	void remove(const string& str); // Removes str if it exists.
	private:
/* Add anything here that you’d like! */
		struct Node{
			string val;
			Node* next;
		};
		int length;
		Node* head;
};
