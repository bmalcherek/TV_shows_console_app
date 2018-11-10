#pragma once
#include <fstream>
#include <string>
#include "Pool.h"
#include "Movie.h"
#include "Live_Event.h"
#include "TV_show.h"


class Database {
public:
	static void save_tv_shows(Pool <TV_show>&);
	static void save_movies(Pool <Movie>&);
	static void save_live_events(Pool <Live_Event>&);
	static void load(Pool <TV_show>&, Pool <Movie>&, Pool <Live_Event>&);
};