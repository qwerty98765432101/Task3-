#include <iostream>
#include "L2.h"
using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");
	L2* list = new L2();
	L2::Iterator* it = new L2::Iterator(list);
	it->begin();

	for (int i = 0; i < 10; i++) {
		list->addElements(i, it);      //��������� ��������
	}
	cout << "������ ����: " << endl;
	list->show(it);
	cout << endl;
	cout << "������� ����� ������� �� ������� ����� " << endl;
	list->deleteElem(it, 5);
	//	it->begin();
	list->show(it);
	cout << endl <<  "�������� ������ ������� �����: ";
	cout << list->getSize();
	cout << endl << "������� ������ ���� " << endl;
	list->makeEmpty();
	list->show(it);
	cout << "�������� ������ ������� ����� (������ ���� ����� ����� �.� ������ - ";
	cout << list->getSize();


	for (int i = 0; i < 12; i++) {
		list->addElements(i, it);
	}for (int i = 0; i < 12; i++) {
		list->addElements(i, it);
	}
	cout <<endl <<  "������ ������� ������ ���� � ���������� ������ " << endl;
	cout << endl << list->getSize();
	cout << endl;
	list->show(it);

	L2* list2 = new L2(list);
	L2::Iterator* it2 = new L2::Iterator(list2);
	cout << endl;
	cout << "������� ������ ���� ������������ ������� " << endl;
	list2->show(it2);
	cout << endl << " -������ 2 ����� - ";
	cout << list2->getSize();

	L2* list3 = new L2(list2);
	L2::Iterator* it3 = new L2::Iterator(list3);
	cout << endl  << "�������� ������������ (list3 = list)" << endl;
	list3 = list;
	cout << "������ 4 ������� ����� �� ����� 20 � ������� 3 ���� " << endl;
	list3->setElement(20, it3, 4);
	list3->show(it3);

	cout <<endl <<  "���� ������ ��������� �������� 9, ���������� �������� �� ���� " << endl;

	if (list->firstIncome(it, 11)->getCurrent()->data == 11) cout << "check completed";

	
}