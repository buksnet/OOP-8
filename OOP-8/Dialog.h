#pragma once
#include "Event.h"
#include "Print.h"

class Dialog : public Event
{
private:
	bool is_running = false;
public:
	Dialog(void);
	virtual ~Dialog(void);
	virtual void getEvent(Event& event);
	virtual void handleEvent(Event& event);
	virtual void clearEvent(Event& event);
	void stop();
	
	virtual void exec();
};
