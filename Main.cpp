#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include "Contact.h"
#include "List.h"
#include "windows.h"
using namespace std;


int main()
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
			cout << "��������: 1\n";
			cout << "�������: 2\n";
			cout << "��������: 3\n";
			cout << "�����: 4\n";
			cout << "�������� � ���������: 5\n";
			cout << "�������� ���������: 6\n";
			cout << "�������� �� ����������: 7\n";
			cout << "�����: 8\n";
			//cin >> menu;

			if (!(cin >> menu)) {
				cin.clear();
				cin.ignore();
				system("cls");
				cout << "������������ ����, �������� �������� �� ������, ����� ��������������� �����";
			}  //��� ���������� ������ ����� 
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
					cout << "������� ����� ������� ��� ��������:\n";
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
					cout << "������� ��� ��� ������: ";
					cin >> word;
					Contact::findObj(word);
					break;
				}
				case 5:
				{

					cout << "������� ID �������� ";
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
					cout << "������� ID ���������� �������� ��� �������� ";
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
