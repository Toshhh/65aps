#pragma once

using namespace std;

class Contact

{

private: // объявление полей контакта
	string name;

	string secName;

	string company;

	string dateBorn;

	string phone;

	string mail;

public: // функции для реализации логики программы

	Contact();
	
	Contact(string, string, string, string, string, string);

	virtual ~Contact();

	void Show(int _i); //показ списка всех контактов
 
	void SetData(); //ввод данных при добавлении контакта

	static void showArr(); 

	static void findObj(string word); 

	static void deleteMass(int _i); 

	void phoneMask(); 

	static void choseCont(int word); //добавление в избранное 

	static void delVip(int word); //удаление из избранного

};
