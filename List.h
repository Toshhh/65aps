#pragma once
#include <list>

using namespace std;

//bool sravn(const List& lhs, const List& rhs) {
//	return &lhs == &rhs;
//}

class Contact;

class List

{

private:

	list<Contact*> Instances;

public:

	~List();
	void AddInst(Contact*);
	void RemoveInst(int);
	void ShowList();
};