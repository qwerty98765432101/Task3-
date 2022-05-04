#pragma once

struct Node {
    Node* Next = nullptr;
    Node* Prev = nullptr;
    double data;
};

class IIterator {
public:
	virtual void begin() = 0;
	virtual void Next() = 0;
	virtual bool finished() = 0;
	virtual Node* getCurrent() = 0;
};