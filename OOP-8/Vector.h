#pragma once
#include "Object.h"

class Vector
{
protected:
	Object** data;
	int max_size;
	int len;
public:
	Vector();
	Vector(int);

	~Vector();

	void reserve(int);

	bool add(Object*);
	bool del();

	void print(bool);
};

