#include "Database.h"


void Database::save_tv_shows(Pool <TV_show>& shows_pool) {
	fstream file;
	int length, number_of_episodes, current_episode;
	string title, tmp;
	float rating;
	bool was_watched;

	file.open("./shows_pool.csv", ios::in | ios::out | ios::trunc);
	for (int i = 0; i < shows_pool.pool.size(); i++) {

		TV_show& show = shows_pool.pool[i];
		length = show.get_length();
		number_of_episodes = show.get_number_of_episodes();
		current_episode = show.get_current_episode();
		title = show.get_title();
		rating = show.get_rating();
		was_watched = show.get_was_watched();

		tmp = title + "," + to_string(length) + "," + to_string(number_of_episodes) + "," + to_string(current_episode) + "," +
			to_string(rating) + "," + to_string(was_watched);

		file << tmp;
	}
}


void Database::save_movies(Pool <Movie>& movies_pool) {
	fstream file;
	int length;
	string title, tmp;
	float rating;
	bool was_watched;

	file.open("./movies_pool.csv", ios::in | ios::out | ios::trunc);
	for (int i = 0; i < movies_pool.pool.size(); i++) {

		Movie& movie = movies_pool.pool[i];
		length = movie.get_length();
		title = movie.get_title();
		rating = movie.get_rating();
		was_watched = movie.get_was_watched();

		tmp = title + "," + to_string(length) + "," + to_string(rating) + "," + to_string(was_watched);

		file << tmp;
	}
}


void Database::save_live_events(Pool <Live_Event>& events_pool) {
	fstream file;
	int length;
	int begin_hour, begin_minute;
	string title, tmp;
	bool was_watched;

	file.open("./events_pool.csv", ios::in | ios::out | ios::trunc);
	for (int i = 0; i < events_pool.pool.size(); i++) {

		Live_Event& live_event = events_pool.pool[i];
		length = live_event.get_length();
		begin_hour = live_event.get_begin_hour();
		begin_minute = live_event.get_begin_minute();
		title = live_event.get_title();
		was_watched = live_event.get_was_watched();

		tmp = title + "," + to_string(length) + "," + to_string(begin_hour) + "," + 
			to_string(begin_minute) + "," + "," + to_string(was_watched);

		file << tmp;
	}
}