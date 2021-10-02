#pragma once

using namespace std;

class Contact

{

private: // объ€вление полей кантакта
	string name;

	string secName;

	string company;

	string dateBorn;

	string phone;

	string mail;

public: // фуекции дл€ реализации логики программы

	Contact();
	
	Contact(string, string, string, string, string, string);

	virtual ~Contact();

	void Show(int _i);
 
	void SetData();

	static void showArr();

	static void findObj(string word);

	static void deleteMass(int _i);

	void phoneMask();

	static void choseCont(int word);

	static void delVip(int word);

};