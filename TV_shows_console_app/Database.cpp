#include "Database.h"


void Database::save_tv_shows(Pool <TV_show>& shows_pool) {
	fstream file;
	int length, number_of_episodes, current_episode;
	string title, tmp;
	float rating;
	bool was_watched;

	file.open("./shows_pool.txt", ios::in | ios::out | ios::trunc);
	for (int i = 0; i < shows_pool.pool.size(); i++) {

		TV_show& show = shows_pool.pool[i];
		length = show.get_length();
		number_of_episodes = show.get_number_of_episodes();
		current_episode = show.get_current_episode();
		title = show.get_title();
		rating = show.get_rating();
		was_watched = show.get_was_watched();

		tmp = title + ";" + to_string(length) + ";" + to_string(number_of_episodes) + ";" + to_string(current_episode) + ";" +
			to_string(rating) + ";" + to_string(was_watched);
		if (i + 1 != shows_pool.pool.size()) {
			tmp += "\n";
		}

		file << tmp;
	}
}


void Database::save_movies(Pool <Movie>& movies_pool) {
	fstream file;
	int length;
	string title, tmp;
	float rating;
	bool was_watched;

	file.open("./movies_pool.txt", ios::in | ios::out | ios::trunc);
	for (int i = 0; i < movies_pool.pool.size(); i++) {

		Movie& movie = movies_pool.pool[i];
		length = movie.get_length();
		title = movie.get_title();
		rating = movie.get_rating();
		was_watched = movie.get_was_watched();

		tmp = title + ";" + to_string(length) + ";" + to_string(rating) + ";" + to_string(was_watched);
		if (i + 1 != movies_pool.pool.size()) {
			tmp += "\n";
		}

		file << tmp;
	}
}


void Database::save_live_events(Pool <Live_Event>& events_pool) {
	fstream file;
	int length;
	int begin_hour, begin_minute;
	string title, tmp;
	bool was_watched;

	file.open("./events_pool.txt", ios::in | ios::out | ios::trunc);
	for (int i = 0; i < events_pool.pool.size(); i++) {

		Live_Event& live_event = events_pool.pool[i];
		length = live_event.get_length();
		begin_hour = live_event.get_begin_hour();
		begin_minute = live_event.get_begin_minute();
		title = live_event.get_title();
		was_watched = live_event.get_was_watched();

		tmp = title + ";" + to_string(length) + ";" + to_string(begin_hour) + ";" +
			to_string(begin_minute) + ";" + to_string(was_watched);
		if (i + 1 != events_pool.pool.size()) {
			tmp += "\n";
		}

		file << tmp;
	}
}


void Database::load(Pool <TV_show>& shows_pool, Pool <Movie>& movies_pool, Pool <Live_Event>& events_pool) {
	fstream spool, mpool, epool;
	string title, var1, var2, var3, var4, var5;
	spool.open("./shows_pool.txt");
	mpool.open("./movies_pool.txt");
	epool.open("./events_pool.txt");

	while (spool.good()) {
		cout << "xd1" << endl;
		getline(spool, title, ';');
		getline(spool, var1, ';');
		getline(spool, var2, ';');
		getline(spool, var3, ';');
		getline(spool, var4, ';');
		getline(spool, var5, '\n');

		TV_show show;
		show.set_title(title);
		show.set_length(stoi(var1));
		show.set_number_of_episodes(stoi(var2));
		show.set_current_episode(stoi(var3));
		show.set_rating(stof(var4));
		if (var5 == "0") {
			show.set_was_watched(false);
		}
		else {
			show.set_was_watched(true);
		}

		shows_pool += show;
	}

	while (mpool.good()) {

		getline(mpool, title, ';');
		getline(mpool, var1, ';');
		getline(mpool, var2, ';');
		getline(mpool, var3, '\n');

		cout << title + var1 + var2 + var3 + "\n";
		Movie movie;
		movie.set_title(title);
		movie.set_length(stoi(var1));
		movie.set_rating(stof(var2));
		if (var3 == "0") {
			movie.set_was_watched(false);
		}
		else {
			movie.set_was_watched(true);
		}

		movies_pool += movie;
	}

	while (epool.good()) {
		cout << "xd3" << endl;
		getline(epool, title, ';');
		getline(epool, var1, ';');
		getline(epool, var2, ';');
		getline(epool, var3, ';');
		getline(epool, var4, '\n');

		Live_Event live_event;
		live_event.set_title(title);
		live_event.set_length(stoi(var1));
		live_event.set_begin_hour(stoi(var2));
		live_event.set_begin_minute(stoi(var3));
		if (var4 == "0") {
			live_event.set_was_watched(false);
		}
		else {
			live_event.set_was_watched(true);
		}

		events_pool += live_event;
	}

	spool.close();
	mpool.close();
	epool.close();
}