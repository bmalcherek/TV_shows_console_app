#pragma once
#include <string>
#include <iostream>
#include "Live_Event.h"
#include "Pool.h"
#include "TV_show.h"
#include "Movie.h"


class Menu {

private:
	Pool <TV_show>& shows_pool;
	Pool <Movie>& movies_pool;
	Pool <Live_Event>& live_events_pool;
	int x;

public:
	Menu(Pool <TV_show>& t, Pool <Movie>& m, Pool <Live_Event>& l) {
		shows_pool = t;
		movies_pool = m;
		live_events_pool = l;
	}
	
	/*void initialize(Pool <TV_show>& t, Pool <Movie>& m, Pool <Live_Event>& l) {
		shows_pool = t;
		movies_pool = m;
		live_events_pool = l;
	}*/
	void main_menu();
};