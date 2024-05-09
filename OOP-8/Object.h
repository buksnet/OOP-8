#pragma once
#include <iostream>

class Object
{
public:
	virtual ~Object() = 0 {}
	Object() {}
	virtual std::string getName() = 0;
	virtual void setInfo() = 0;
	virtual void getInfo(bool names_only = false) = 0;
};
