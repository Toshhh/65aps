#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include "Contact.h"
#include <algorithm>
#include "List.h"
#include <conio.h>
#include <ctype.h>

using namespace std;
vector<string> arr;
vector<string> arrChosen;
int k;
string d;

bool isTrue(string value)
{
	return (value == value);
}

bool isTrue1(string value)
{
	return (value == value);
}


Contact::Contact(string _name, string _secName, string _company, string _dateBorn, string _phone, string _mail)

{
	name = _name;

	secName = _secName;

	company = _company;

	dateBorn = _dateBorn;

	phone = _phone;

	mail = _mail;
}

Contact::~Contact()

{

	cout << endl << "Вызван деструктор" << endl;

}

void Contact::Show(int _id)

{

	cout << endl << "ID: " << _id << endl << "Имя: " << name << endl << "Фамилия: " << secName << endl << "Компания: " << company << endl  << "Дата рождения: " << dateBorn << endl << "Номер телефона: " << phone << endl<< "e-mail: " << mail << endl;

}

Contact::Contact()

{

	SetData();

}

void Contact::showArr()
{
	int a = 0;
	if (arrChosen.size() != 0) {
		for (int i = 0; i < arrChosen.size(); i++)
		{

			cout << endl << "ID избранного: " << a << endl << "Имя: " << arrChosen[i] << endl << "Фамилия: " << arrChosen[i + 1] << endl << "Компания: " << arrChosen[i + 2] << endl << "Дата рождения: " << arrChosen[i + 3] << endl << "Номер телефона: " << arrChosen[i + 4] << endl << "e-mail: " << arrChosen[i + 5] << endl;

			i = i + 5;
			a++;
			cout << endl;
		}
	}
	else
	{
		cout << "Список избранных пуст";
	}

}

void Contact::delVip(int word)
{
	if (arrChosen.size() != 0) {
		int k = word * 6;

		auto it1 = arrChosen.begin() + k;

		auto newEnd = remove_if(it1, it1 + 6, isTrue);

		auto z = arrChosen.begin() + k;

		arrChosen.erase(newEnd, z + 6);

		cout << "Контакт удален" << endl;
	}
	else {
		cout << "В избранном нет такого ID" << endl;
	}
	///////////////////////////////////////////////////

	/*if (arrChosen.size() != 0) {
		it1 = arrChosen.begin() + k;

		newEnd = remove_if(it1, it1 + 6, isTrue);

		z = arrChosen.begin() + k;

		arrChosen.erase(newEnd, z + 6);
	}*/
}


void Contact::findObj(string word) 
// я не разобрался, как можно быстро искать эллемент в списке, поэтому сделал вот такой костыль
// причем поиск по списку идет через такую же конструкцию find + булева функция для сравнения эл-ов, но я что-то затупил тут...
{
	bool a = true;

	for (int i = 0; i < arr.size(); ++i) {

		if (arr[i].find(word) == 0) {
		
			cout << endl << "Имя: " << arr[i] << endl << "Фамилия: " << arr[i + 1] << endl << "Компания: " << arr[i + 2] << endl << "Дата рождения: " << arr[i + 3] << endl << "Номер телефона: " << arr[i + 4] << endl << "e-mail: " << arr[i + 5] << endl;
		
			i = i + 5;

			a = false;

		}
	}

	if (a) {

		cout << "Контакт не найден" << endl;
	}
}

void Contact::choseCont(int word)
{
	if (arr.size() > word * 6) {
		int k = word * 6;

		for (int i = k; i < k + 6; i++) {

			if (i == k) {

				arrChosen.push_back(arr[i]);

				arrChosen.push_back(arr[i + 1]);

				arrChosen.push_back(arr[i + 2]);

				arrChosen.push_back(arr[i + 2]);

				arrChosen.push_back(arr[i + 4]);

				arrChosen.push_back(arr[i + 5]);

				break;
			}
		}
	}

}

void Contact::deleteMass(int word)
{
	int k = word * 6;

	auto it1 = arr.begin() + k;

	auto newEnd = remove_if(it1, it1 + 6, isTrue);

	auto z = arr.begin() + k;

	arr.erase(newEnd, z + 6);

	///////////////////////////////////////////////////
	
	/*if (arrChosen.size() != 0) {
		it1 = arrChosen.begin() + k;

		newEnd = remove_if(it1, it1 + 6, isTrue);

		z = arrChosen.begin() + k;

		arrChosen.erase(newEnd, z + 6);
	}*/
}

void Contact::phoneMask()
{
	int length = 0;

	int pospos = 0;

	int posarrays[10] = { 3,4,5,7,8,9,11,12,14,15 };

	int pos = posarrays[pospos];

	char mask[17] = "+7(***)***-**-**";

	cout << mask;

	while (length != 10) {

		int ch = _getche();

		if (ch >= '0' && ch <= '9') {

			length++;

			mask[pos] = ch;

			system("cls");

			pospos++;

			pos = posarrays[pospos];

			cout << mask;
		}
	}

	arr.push_back(mask);

	phone = mask;
}

void Contact::SetData()

{

	cout << "Введите имя: "; cin >> name;

	arr.push_back(name);

	cout << "Введите фамилию: "; cin >> secName;

	arr.push_back(secName);

	cout << "Введите компанию: "; cin >> company;

	arr.push_back(company);

	cout << "Введите дату рождения: "; cin >> dateBorn;

	arr.push_back(dateBorn);

	cout << "Введите номер телефона: "; //cin >> phone;

	phoneMask();
	
	cout << endl << "Введите e-mail: "; cin >> mail;

	arr.push_back(mail);

}