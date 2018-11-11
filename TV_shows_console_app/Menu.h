#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include "Live_Event.h"
#include "TV_show.h"
#include "Movie.h"
#include "Database.h"
#include "BadValueException.h"


class Menu {

private:

public:
	void main_menu(Pool <TV_show>&, Pool <Movie>&, Pool <Live_Event>&);
	void add_menu(Pool <TV_show>&, Pool <Movie>&, Pool <Live_Event>&);
	void edit_menu(Pool <TV_show>&, Pool <Movie>&, Pool <Live_Event>&);
	void delete_menu(Pool <TV_show>&, Pool <Movie>&, Pool <Live_Event>&);
	void sort_menu(Pool <TV_show>&, Pool <Movie>&);
	void edit_show(Pool <TV_show>&);
	void edit_movie(Pool <Movie>&);
	void edit_live_event(Pool <Live_Event>&);
	void delete_show(Pool <TV_show>&);
	void delete_movie(Pool <Movie>&);
	void delete_live_event(Pool <Live_Event>&);
	void recommend(Pool <TV_show>&, Pool <Movie>&);
	void statistics(Pool <TV_show>&, Pool <Movie>&, Pool <Live_Event>&);
	void live_events(Pool <Live_Event>&);
	TV_show add_show();
	Movie add_movie();
	Live_Event add_live_event();
};