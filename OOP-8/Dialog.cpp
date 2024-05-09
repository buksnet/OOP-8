#include "Event.h"
#include "Print.h"
#include <iostream>
#include <string>
using namespace std;

Dialog::Dialog() {
	this->is_running = true;
}

Dialog::~Dialog() {}

void Dialog::execute() {
	Event ev;
	while (this->is_running) {
		cout << "Pick an action for program:" << endl
			<< "'m' - create new group; args: group size" << endl
			<< "'+' - add element to current group; args: 1 - Magazine, 2 - Print" << endl
			<< "'-' - delete current group" << endl
			<< "'s' - print data of current group" << endl
			<< "'z' - print only names of current group" << endl
			<< "'q' - stop listening to input" << endl
			<< endl << "~$ ";
		this->getEvent(ev);
		this->response(ev);
		cout << endl;
	}
}

void Dialog::getEvent(Event& ev) {
	string cmds = "m+-szq", input;
	getline(cin, input);
	if (cmds.find(input[0]) >= 0) {
		ev.isEmpty = new_message;
		switch (input[0])
		{
		case 'm': ev.command = createGroup; break;
		case '+': ev.command = addElem; break;
		case '-': ev.command = delElem; break;
		case 's': ev.command = printData; break;
		case 'z': ev.command = printNames; break;
		case 'q': ev.command = stopExec; break;
		}
		if (input.length() > 1) {
			int arg = atoi(input.substr(1, input.size() - 1).c_str());
			ev.arg = arg;
			if (arg <= 0) {
				cout << "Wrong input!" << endl;
				ev.isEmpty = ev_empty;
			}
		}
	}
	else ev.isEmpty = ev_empty;
}

void Dialog::response(Event& ev) {
	if (!ev.isEmpty) {
		switch (ev.command) {
		case createGroup: this->reserve(ev.arg);
			break;
		case addElem:
			if (ev.arg == 1) {
				Magazine* elem = new Magazine;
				elem->setInfo();
				this->add(elem);
			}
			else {
				Print* elem = new Print;
				elem->setInfo();
				this->add(elem);
			}
			break;
		case delElem: this->del(); break;
		case printData: this->print(false); break;
		case printNames: this->print(true); break;
		case stopExec: this->is_running = false;
		default: break;
		}
	}
	ev.clear();
}