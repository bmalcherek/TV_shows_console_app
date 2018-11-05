#include "Database.h"


void Database::save_tv_shows(Pool <TV_show>& shows_pool) {
	fstream shows_pool_save;
	int length, number_of_episodes, current_episode;
	string title;
	float rating;
	bool was_watched;

	shows_pool_save.open("shows_pool.txt");
	for (int i = 0; i < shows_pool.pool.size(); i++) {

		TV_show& show = shows_pool.pool[i];
		length = show.get_length();
		number_of_episodes = show.get_number_of_episodes();
		current_episode = show.get_current_episode();
		title = show.get_title();
		rating = show.get_rating();
		was_watched = show.get_was_watched();

		
	}
}