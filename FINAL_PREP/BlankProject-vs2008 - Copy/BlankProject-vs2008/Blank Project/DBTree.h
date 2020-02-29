#pragma once

class DBTree
{
public:
	DBTree();
	~DBTree();
	void Insert(int value);
	void Remove(int value);
private:
	struct tree{
		int val1;
		int val2;
		tree* left;
		tree* mid;
		tree* right;
	};
	tree* root;
	int ExtractSmallest();
	tree* smallest(tree*& subtree);
	int ExtractLargest(); // es vitom ukve miweria :D  suuuuuure 
	tree* largest(tree*& subtree);
};
