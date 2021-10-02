#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include "Contact.h"
#include "List.h"
#include "windows.h"
using namespace std;

int main()                //основной файл main
{ 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	List* ContactList = new List;
	{
		string word;
		int menu = 0;
		int chC;
		bool isWork = true;
		while (isWork == true)
		{
			cout << endl;
			cout << "Добавить: 1\n";
			cout << "Удалить: 2\n";
			cout << "Показать: 3\n";
			cout << "Найти: 4\n";
			cout << "Добавить в избранное: 5\n";
			cout << "Просмотр избранных: 6\n";
			cout << "Удаление из избранного: 7\n";
			cout << "Выход: 8\n";
			//cin >> menu;

			if (!(cin >> menu)) {
				cin.clear();
				cin.ignore();
				system("cls");
				cout << "Неправильный ввод, выберите действие из списка, задав соответствующую цифру";
			}  //для устранения ошибки ввода 
				switch (menu)

				{
				case 1:
				{
					Contact* mgzn = new Contact;
					ContactList->AddInst(mgzn);
					break;
				}

				case 2:
				{
					cout << "Введите номер индекса для удаления:\n";
					cin >> menu;
					if (menu) {
						ContactList->RemoveInst(menu);
					}
					break;
				}

				case 3:
				{
					ContactList->ShowList();
					break;

				}
				case 4:
				{
					cout << "Введите имя для поиска: ";
					cin >> word;
					Contact::findObj(word);
					break;
				}
				case 5:
				{

					cout << "Введите ID контакта ";
					cin >> chC;
					Contact::choseCont(chC);
					break;
				}

				case 6:
				{
					Contact::showArr();
					break;

				}

				case 7:
				{
					cout << "Введите ID избранного контакта для удаления ";
					cin >> chC;
					Contact::delVip(chC);
					break;
				}
				case 8:
				{
					isWork = false;
					delete ContactList;
					break;
				}
				}
			
		}
	}

	system("pause");
}
