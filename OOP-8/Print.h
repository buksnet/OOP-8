#pragma once
#include "Object.h"
#include <iostream>

using namespace std;

class Print : public Object
{
protected:
	string name;
	string author;
public:
	Print() {}
	Print(string, string) {}
	virtual ~Print() {}

	void setName(string name) { this->name = name; }
	void setAuthor(string author) { this->author = author; }

	string getName() { return this->name; }
	string getAuthor() { return this->author; }

	virtual void setInfo();
	virtual void getInfo(bool);

	Print& operator=(Print&);
};

class Magazine : public Print
{
protected:
	int pages;
public:
	Magazine() :Print() { this->pages = 0; }
	Magazine(string, string, int);
	virtual ~Magazine() {}

	void setPages(int pages) { this->pages = pages; }
	int getPages() { return pages; }

	virtual void setInfo();
	virtual void getInfo(bool);

	Magazine& operator=(Magazine&);
};
