#include <iostream>
#include "L2.h"
#include <stdlib.h>

void L2::Iterator::begin() {
    
        current = iterator->Head;
    
}
void L2::Iterator::Next() {

        current = current->Next;

}

 Node* L2::Iterator::getCurrent() {
    return current;

}
bool L2::Iterator::finished() {
    return current ==  iterator->Head;
  }

void L2::addElements(double elem, IIterator* it) {
    if (size == 0) {
        Head->data = elem;
        size++;
    }
    else {
        size++;
        Node* current = new Node;
        current->data = elem;
        current->Prev = it->getCurrent();
        current->Next = Head;
        it->getCurrent()->Next = current;
        Head->Prev = current;
        it->Next();
    }
}

void L2::setElement(double elem, IIterator* it, int num)
{
 
    int  count = 0;
    if (num < size + 1) {
        while (count != num) {
            it->Next();
            count++;
        }
        it->getCurrent()->data = elem;
    }
}

void L2::deleteElem(IIterator* it, int num) {
    it->begin();
    int count = 0;
    if (num <= size) {
        while (count != num) {
            it->Next();
            count++;
        }
        it->getCurrent()->Next->Prev = it->getCurrent()->Prev;
        it->getCurrent()->Prev->Next = it->getCurrent()->Next;
        delete it->getCurrent();
        size--;
    }
}

IIterator* L2::firstIncome(IIterator* it, double elem) {
    it->begin();

    if (it->getCurrent()->data == elem) {
   
        return it;
    }
    it->Next();

    while(it->getCurrent()->data != elem && it->finished() != 1){
       
       
        it->Next();
    } 
    if (it->getCurrent()->data == elem) {
        return it;
    }
return nullptr;
}



void L2::makeEmpty() {
    Head = Head->Next;
    for (int i = 0; i < size - 1; i++) {
        Head = Head->Next;
        delete Head->Prev;
    }
    Head->Next = Head;
    Head->Prev = Head;
    size = 0;
}



void L2::show(IIterator *it) {
    int curr = 0;
    it->begin();
    while (size != curr) {
        std::cout << it->getCurrent()->data << " ";
        it->Next();
        curr++;
        

    }


}
bool L2::checkEmpty() {
    return size == 0;
}

int L2::getSize() {
    return size;
}
IIterator* L2::getFirst(IIterator* it) {
    it->begin();
    return it;
}
L2 L2::operator =(const L2* obj) {
   if (this == obj) {
       return this;
   }
   else {
       makeEmpty();
       size = obj->size;
       Node* copy = new Node;
       copy = obj->Head;
       Node* Tail = new Node;
       Tail = Head;
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
       return this;

   }
}




