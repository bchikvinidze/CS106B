#ifndef Gridz_H
#define Gridz_H


template <typename type>
class Gridz {
public:
	Gridz();
	Gridz(int nRows, int nCols);
	~Gridz();
	type getAt(int row, int col);
	void setAt(int row, int col, type value);
	void resize(int newRows, int newCols);
	bool inBounds(int row, int col);
	int numRows();
	int numCols();
	//type & operator[][](int row, int col);
	//void & operator[][](int row, int col, type value);
private:
	struct Node{
		type val;
		Node * next;
	};
	Node ** start;
	int r;
	int c;
};

#endif