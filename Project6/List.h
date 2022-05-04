#pragma once
#include "Iterator.h"

class LList {

public:

	virtual void addElements(double elem, IIterator* it) = 0;
	virtual void setElement(double elem, IIterator* it, int num) = 0;
	virtual void deleteElem(IIterator* it, int num) = 0;
	virtual IIterator* firstIncome(IIterator* it, double elem) = 0;
	virtual void makeEmpty() = 0;
	virtual bool checkEmpty() = 0;
	virtual int getSize() = 0;
	virtual IIterator* getFirst(IIterator *it) = 0;
	
};