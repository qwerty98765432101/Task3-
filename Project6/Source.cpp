#include <iostream>
#include "L2.h"
using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");
	L2* list = new L2();
	L2::Iterator* it = new L2::Iterator(list);
	it->begin();

	for (int i = 0; i < 10; i++) {
		list->addElements(i, it);      //Добавляем элементы
	}
	cout << "Первый лист: " << endl;
	list->show(it);
	cout << endl;
	cout << "Удаляем пятый элемент из первого листа " << endl;
	list->deleteElem(it, 5);
	//	it->begin();
	list->show(it);
	cout << endl <<  "Получаем размер первого листа: ";
	cout << list->getSize();
	cout << endl << "Удаляем первый лист " << endl;
	list->makeEmpty();
	list->show(it);
	cout << "Получаем размер первого листа (должен быть равен нулюб т.к удален - ";
	cout << list->getSize();


	for (int i = 0; i < 12; i++) {
		list->addElements(i, it);
	}for (int i = 0; i < 12; i++) {
		list->addElements(i, it);
	}
	cout <<endl <<  "Заного создаем первый лист и показываем размер " << endl;
	cout << endl << list->getSize();
	cout << endl;
	list->show(it);

	L2* list2 = new L2(list);
	L2::Iterator* it2 = new L2::Iterator(list2);
	cout << endl;
	cout << "Создаем второй лист копированием первого " << endl;
	list2->show(it2);
	cout << endl << " -размер 2 листа - ";
	cout << list2->getSize();

	L2* list3 = new L2(list2);
	L2::Iterator* it3 = new L2::Iterator(list3);
	cout << endl  << "Оператор присваивания (list3 = list)" << endl;
	list3 = list;
	cout << "Меняем 4 элемент листа на число 20 и выводим 3 лист " << endl;
	list3->setElement(20, it3, 4);
	list3->show(it3);

	cout <<endl <<  "Ищем первое вхождение элемента 9, возвращаем итератор на него " << endl;

	if (list->firstIncome(it, 11)->getCurrent()->data == 11) cout << "check completed";

	
}