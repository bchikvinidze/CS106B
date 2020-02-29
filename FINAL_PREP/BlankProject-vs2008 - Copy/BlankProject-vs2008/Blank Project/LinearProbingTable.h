#pragma once

#include "vector.h"

class LinearProbingTable{
public: 
	LinearProbingTable();
	bool contains(int value) const;
	void add(int value);
	int size() const;
	bool isEmpty() const;
private:
	Vector<int> table;
	int length;
	void rehash();
};
