#pragma once
#include <string>
class myString
{
public:
	myString(void);
	~myString(void);
	string getValue(); // mtlian strings abrunebs (linkedlist ro miawebo)
	void setValue(string s); // gadaecema string da amit chaanacvlebs linkedlists
	string substr2(int index, int len);
	int find(string s); //edzebs indeqss -(tu ver ipova aseti stringi mashin -1;
	int size();
	void insert(int index, string s);
	void remove(int index, int len); //igive substr ogond shlis
private:
	struct Cell{
		char ch;
		Cell * next;
	}
	Cell * head
	int length2;
	string getValueWrapper(Cell* cur);
	Cell * createList(string s);
};
