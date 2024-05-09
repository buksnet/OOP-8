#include "Vector.h"
#include <iostream>

using namespace std;

Vector::Vector() {
	this->data = nullptr;
	this->max_size = 0;
	this->len = 0;
}

Vector::Vector(int data) {
	this->data = new Object * [data];
	this->max_size = data;
	this->len = 0;
}

Vector::~Vector() {}

void Vector::reserve(int length) {
	if (!(this->data == nullptr)) {
		for (int i = 0; i < this->len; i++) {
			delete this->data[i];
		}
		delete[] this->data;
	}
	this->max_size = length;
	this->data = new Object*[length];
	this->len = 0;
};

bool Vector::add(Object* obj) {
	if (this->len >= this->max_size) {
		cout << "GroupOverflow Error!" << endl;
		return false;
	}
	this->data[this->len] = obj;
	this->len++;
	return true;
}

bool Vector::del() {
	string name;
	cout << "Enter name of element to delete: ";
	cin >> name;
	if (this->len == 0) {
		cout << "NoElements Error!" << endl;
		return false;
	}
	bool f = false;
	for (int i = 0; i < this->len && !f; i++) {
		if (this->data[i]->getName() == name) {
			Object* tmp = this->data[i];
			for (int j = i; i < this->len-1; j++) {
				this->data[j] = this->data[j + 1];
			}
			delete tmp;
			this->len--;
		}
	}
	if (!f) cout << "NotFound Error!" << endl;
	return f;
}

void Vector::print(bool nameOnly = false) {
	cout << "class 'Vector' information:" << endl;
	if (this->len == 0) {
		cout << "This group is empty!" << endl;
		return;
	}
	this->data[0]->getInfo(nameOnly);

	for (int i = 1; i < this->len; i++) {
		cout << endl;
		this->data[i]->getInfo(nameOnly);
	}
}
