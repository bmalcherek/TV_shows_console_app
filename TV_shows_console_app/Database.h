#pragma once
#include <fstream>
#include <string>
#include "Pool.h"
#include "Movie.h"
#include "Live_Event.h"
#include "TV_show.h"


class Database {
public:
	void save_tv_shows(Pool <TV_show>&);
	void save_movies(Pool <Movie>&);
	void save_live_events(Pool <Live_Event>&);
	void load();
};