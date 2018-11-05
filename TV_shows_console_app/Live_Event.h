#pragma once
#include "Watchable_Element.h"


class Live_Event : public Watchable_Element {

private:
	int begin_hour, begin_minute;

public:
	void set_begin_hour(int h) { begin_hour = h; }
	int get_begin_hour() { return begin_hour; }
	void set_begin_minute(int m) { begin_minute = m; }
	int get_begin_minute() { return begin_minute; }
};