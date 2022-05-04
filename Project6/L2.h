#pragma once
#include "List.h"
#include <iostream>


class L2 : public LList {

	Node* Head;
	int size = 0;
public:
	L2() {
		Head = new Node;
		Head->Next = Head;
		Head->Prev = Head;
	}
	L2(L2* obj) {
		size = obj->size;
		Node* copy = new Node;
		copy = obj->Head;
		Head = new Node;
		Node* Tail = Head;

		Head->Next = Tail;
		Tail->Prev = Head;
		Head->data = copy->data;
		copy = copy->Next;
		for (int i = 0; i < size; i++) {
			Node* temp = new Node;
			temp->data = copy->data;
			Head->Prev = temp;
			temp->Next = Head;
			temp->Prev = Tail;
			Tail->Next = temp;
			Tail = temp;
			copy = copy->Next;
		}
	}
	L2(L2&& obj) noexcept {
		size = obj.size;
		std::swap(Head, obj.Head);
	}


	class Iterator : public IIterator {
	private:


		L2* iterator;
		Node* current = nullptr;

	public:
		Iterator(L2* obj) {
			iterator = obj;
			current = obj->Head;
		}

		void begin() override;

		void Next() override;

		Node* getCurrent() override;

		bool finished() override ;




	};
	

	void addElements(double elem, IIterator* it) override ;

	void setElement(double elem, IIterator* it, int num) override;

	void deleteElem(IIterator* it, int num) override ;

	IIterator* firstIncome(IIterator* it, double elem) override;

	void makeEmpty() override;

	bool checkEmpty() override;

	int getSize() override ;

	IIterator* getFirst(IIterator* it) override;

	void show(IIterator* it);

	L2 operator = (const L2* obj);


};