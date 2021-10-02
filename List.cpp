#include <iostream>
#include "Contact.h"
#include "List.h"
#include <iterator>
#include <vector>

vector<string> spis;

void List::AddInst(Contact* ref)

{

	Instances.push_back(ref);

	cout << "Объект добавлен\n";

}

void List::RemoveInst(int id)

{

	list<Contact*>::iterator iter = Instances.begin();

	if (Instances.size() <= id || id < 0)

	{

		cout << "ID не существует\n";

		return;

	}

	advance(iter, id);

	Instances.remove(*iter);

	Contact::deleteMass(id);

	cout << "Объект удален\n";

}

//void List::Naidy(int word) {
//
//	//auto i = m.find(*it); //Если элемент найден, то i будет содержать индекс элемента, либо npos, если элемент не найден
//	//while (i != npos) {//если элемент был найден, то i будет не равен npos и цикл продолжится
//	//	cout << "est\n";
//	//	i = m.find(*it, i + 1); //ищем следующее вхождение элемента в строку, начиная с позиции i + 1, т.к. в позиции i у нас стоит нужный элемент
//	//}//когда элементов со значением *it в строке не останется, find вернет npos и программа выйдет из цикла
//
//	list<Contact*>::iterator iter = Instances.begin();
//
//	list<Contact*>::iterator iterend = Instances.end();
//	
//	int i = 0;
//
//	while (iter != iterend)
//
//	{
//		Contact* pListEl = (*iter);
//		
//		spis.push_back()
//		if ()
//		{
//			pListEl->Show(i);
//		}
//		 
//
//		pListEl->Show(i);
//
//		iter++;
//
//		i++;
//
//	}
//}

void List::ShowList()

{

	if (Instances.size() == 0)

	{

		cout << "Список пуст" << endl;

		return;

	}

	list<Contact*>::iterator iter = Instances.begin();

	list<Contact*>::iterator iterend = Instances.end();

	int i = 0;

	while (iter != iterend)

	{
	
		Contact* pListEl = (*iter);

		pListEl->Show(i);

		iter++;

		i++;

	}

}


List::~List()

{

	if (Instances.size() == 0)

	{

		cout << "Список пуст" << endl;

		return;

	}

	list<Contact*>::iterator iter = Instances.begin();

	while (Instances.size() != 0)

	{

		Contact* pListEl = (*iter);

		delete pListEl;

		Instances.remove(*iter);

		list<Contact*>::iterator iter = Instances.begin();

	}

}