#pragma once

class RevQueue
{
public:
	RevQueue();
	~RevQueue();
	void reverse();
private:
	struct Cell {
		string value;
		Cell* next;
	};
	Cell* head;
	Cell* tail;
	int count;
	void reverseWrapper(Node * node);
};
