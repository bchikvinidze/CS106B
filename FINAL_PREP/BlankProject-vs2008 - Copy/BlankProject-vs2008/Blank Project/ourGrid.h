#pragma once

class ourGrid
{
public:
	ourGrid();
	~ourGrid();
	void addColumn();
	void addRow();
	void setValue(int row, int col, int value);
private:
	struct Node{
		int value;
		Node* right;
		Node* down;
	};
	Node* head;
	int nRows;
	int nCols;
	void deleteRow(Node* node);
};
