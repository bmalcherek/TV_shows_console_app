#include "User.h"
#include "Menu.h"
#include "Live_Event.h"
#include "Pool.h"
#include "TV_show.h"
#include "Movie.h"
#include <iostream>
#include <string>

int main() {
	Pool <TV_show> shows_pool;
	Pool <Movie> movies_pool;
	Pool <Live_Event> live_events_pool;
	Database::load(shows_pool, movies_pool, live_events_pool);
	if (!live_events_pool.pool.empty()) {
		cout << "xd";
		system("pause");
	}
	Menu menu;
	menu.main_menu(shows_pool, movies_pool, live_events_pool);	
	system("pause");
	return 0;
}