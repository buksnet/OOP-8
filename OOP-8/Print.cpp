#include "Print.h"
#include <iostream>
#include <string>

using namespace std;

void Print::setInfo() {
	cout << "Input name: ";
	getline(cin, this->name);
	cout << "Input author: ";
	getline(cin, this->author);
}

void Print::getInfo(bool nameOnly=true) {
	cout << "class 'Print' information:" << endl;
	cout << "Name: " << getName() << endl;
	if (!nameOnly) {
		cout << "Author: " << getAuthor() << endl;
	}
}

Print& Print::operator=(Print& P) {
	this->name = P.name;
	this->author = P.author;
	return *this;
}

Magazine::Magazine(string name, string author, int pages) {
	this->name = name;
	this->author = author;
	this->pages = pages;
}

void Magazine::setInfo() {
	cout << "Input name: ";
	getline(cin, this->name);
	cout << "Input author: ";
	getline(cin, this->author);
	cout << "Input pages count: ";
	cin >> this->pages;
}

void Magazine::getInfo(bool nameOnly = true){
	cout << "class 'Magazine' information:" << endl;
	cout << "Name: " << getName() << endl;
	if (!nameOnly) {
		cout << "Author: " << getAuthor() << endl;
		cout << "Pages count: " << getPages() << endl;
	}
}

Magazine& Magazine::operator=(Magazine& M) {
	this->name = M.name;
	this->author = M.author;
	this->pages = M.pages;
	return *this;
}