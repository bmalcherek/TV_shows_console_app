#pragma once
#include <string>
#include <iostream>
#include "Live_Event.h"
#include "Pool.h"
#include "TV_show.h"
#include "Movie.h"


class Menu {

private:

public:
	void main_menu(Pool <TV_show>&, Pool <Movie>&, Pool <Live_Event>&);
	void add_menu(Pool <TV_show>&, Pool <Movie>&, Pool <Live_Event>&);
	void edit_menu(Pool <TV_show>&, Pool <Movie>&, Pool <Live_Event>&);
	void edit_show(Pool <TV_show>&);
	TV_show add_show();
	Movie add_movie();
	Live_Event add_live_event();
};