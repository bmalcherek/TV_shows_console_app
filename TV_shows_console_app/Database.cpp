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

		system("CLS");
		cout << tmp;
		system("pause");

		if (i + 1 != events_pool.pool.size()) {
			tmp += "\n";
		}

		file << tmp;
	}
}


void Database::load(Pool <TV_show>& shows_pool, Pool <Movie>& movies_pool, Pool <Live_Event>& events_pool) {
	fstream spool, mpool, epool;
	//string title, var1, var2, var3, var4, var5;
	string title, tmp;
	spool.open("./shows_pool.txt");
	mpool.open("./movies_pool.txt");
	epool.open("./events_pool.txt");

	while (spool.good()) {

		TV_show show;

		getline(spool, title, ';');
		show.set_title(title);
		getline(spool, tmp, ';');
		show.set_length(stoi(tmp));
		getline(spool, tmp, ';');
		show.set_number_of_episodes(stoi(tmp));
		getline(spool, tmp, ';');
		show.set_current_episode(stoi(tmp));
		getline(spool, tmp, ';');
		show.set_rating(stof(tmp));
		getline(spool, tmp, '\n');
			
		if (tmp == "0") {
			show.set_was_watched(false);
		}
		else {
			show.set_was_watched(true);
		}

		shows_pool += show;
	}

	cout << "Shows loaded" << endl;

	while (mpool.good()) {

		Movie movie;
		getline(mpool, title, ';');
		movie.set_title(title);
		getline(mpool, tmp, ';');
		movie.set_length(stoi(tmp));
		getline(mpool, tmp, ';');
		movie.set_rating(stof(tmp));
		getline(mpool, tmp, '\n');
		if (tmp == "0") {
			movie.set_was_watched(false);
		}
		else {
			movie.set_was_watched(true);
		}

		movies_pool += movie;
	}

	cout << "Movies loaded" << endl;
	
	while (epool.good()) {

		Live_Event live_event;
		getline(epool, title, ';');
		live_event.set_title(title);
		getline(epool, tmp, ';');
		live_event.set_length(stoi(tmp));
		getline(epool, tmp, ';');
		live_event.set_begin_hour(stoi(tmp));
		getline(epool, tmp, ';');
		live_event.set_begin_minute(stoi(tmp));
		getline(epool, tmp, '\n');
		if (tmp == "0") {
			live_event.set_was_watched(false);
		}
		else {
			live_event.set_was_watched(true);
		}

		events_pool += live_event;
	}

	cout << "Events loaded" << endl;

	spool.close();
	mpool.close();
	epool.close();
}