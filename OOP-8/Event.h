#pragma once
#include "Vector.h"

const bool ev_empty = true;
const bool new_message = false;

const char createGroup = 'm';
const char addElem = '+';
const char delElem = '-';
const char printData = 's';
const char printNames = 'z';
const char stopExec = 'q';

class Event
{
public:
	bool isEmpty;
	struct {
		char command;  //command with argument
		int arg;
	};

	void clear() {
		isEmpty = ev_empty;
		command = ' ';
		arg = 0;
	}
};


class Dialog : public Vector {
protected:
	bool is_running;
public:
	Dialog();
	~Dialog();

	void execute();
	void getEvent(Event&);
	void response(Event&);
};