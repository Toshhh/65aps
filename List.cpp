#include <iostream>
#include "Contact.h"
#include "List.h"
#include <iterator>
#include <vector>

vector<string> spis;

void List::AddInst(Contact* ref)

{

	Instances.push_back(ref);

	cout << "������ ��������\n";

}

void List::RemoveInst(int id)

{

	list<Contact*>::iterator iter = Instances.begin();

	if (Instances.size() <= id || id < 0)

	{

		cout << "ID �� ����������\n";

		return;

	}

	advance(iter, id);

	Instances.remove(*iter);

	Contact::deleteMass(id);

	cout << "������ ������\n";

}

//void List::Naidy(int word) {
//
//	//auto i = m.find(*it); //���� ������� ������, �� i ����� ��������� ������ ��������, ���� npos, ���� ������� �� ������
//	//while (i != npos) {//���� ������� ��� ������, �� i ����� �� ����� npos � ���� �����������
//	//	cout << "est\n";
//	//	i = m.find(*it, i + 1); //���� ��������� ��������� �������� � ������, ������� � ������� i + 1, �.�. � ������� i � ��� ����� ������ �������
//	//}//����� ��������� �� ��������� *it � ������ �� ���������, find ������ npos � ��������� ������ �� �����
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

		cout << "������ ����" << endl;

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

		cout << "������ ����" << endl;

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