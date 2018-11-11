#include "Menu.h"
using namespace std;


void Menu::main_menu(Pool <TV_show>& shows_pool, Pool <Movie>& movies_pool, Pool <Live_Event>& events_pool) {
	int choose;
	system("CLS");
	cout << "Hi, what would you like to do?\n1. Add show/movie/live show\n" <<
		"2. Edit show/movie/live show\n3. Delete show/movie/live show\n4. Show by rating\n5. Recommend show or movie\n"<<
		"6. Show statistics\n9. Exit\nEnter number: ";
	cin >> choose;
	system("CLS");
	switch (choose) {

	case 1: {
		add_menu(shows_pool, movies_pool, events_pool);
		break;
	}

	case 2: {
		edit_menu(shows_pool, movies_pool, events_pool);
		break;
	}		

	case 3: {
		delete_menu(shows_pool, movies_pool, events_pool);
		break;
	}

	case 4: {
		sort_menu(shows_pool, movies_pool);
		break;
	}

	case 5: {
		recommend(shows_pool, movies_pool);
		break;
	}

	case 6: {
		statistics(shows_pool, movies_pool, events_pool);
		break;
	}

	case 9:
		exit(0);
	}

	if (!events_pool.pool.empty()) {
		cout << "xd";
		system("pause");
	}
	Database::save_tv_shows(shows_pool);
	Database::save_movies(movies_pool);
	Database::save_live_events(events_pool);
	main_menu(shows_pool, movies_pool, events_pool);
}


//ADDING SECTION


void Menu::add_menu(Pool <TV_show>& shows_pool, Pool <Movie>& movies_pool, Pool <Live_Event>& events_pool) {
	int choose2;
	system("CLS");
	cout << "1. Add show\n2. Add movie\n3. Add live show\n9. Go back\nEnter number: ";
	cin >> choose2;
	switch (choose2) {

	case 1: {
		TV_show show = add_show();
		shows_pool += show;
		break;
	}

	case 2: {
		Movie movie = add_movie();
		movies_pool += movie;
		break;
	}

	case 3: {
		Live_Event live_event = add_live_event();
		events_pool += live_event;
		break;
	}
	}
}


TV_show Menu::add_show() {
	TV_show show;
	string title;
	int length, number_of_episodes;
	float rating;

	system("CLS");
	cout << "What is the title of the show?: ";
	cin.ignore();
	getline(cin, title);
	cout << "How long is 1 episode on average?: ";
	cin >> length;
	cout << "How many episodes does the show have?: ";
	cin >> number_of_episodes;
	cout << "What is the rating of the show (from IMDb)?: ";
	cin >> rating;

	show.set_title(title);
	show.set_length(length);
	show.set_number_of_episodes(number_of_episodes);
	show.set_rating(rating);
	show.set_current_episode(0);
	show.set_was_watched(false);

	return show;
}


Movie Menu::add_movie() {
	Movie movie;
	string title;
	int length;
	float rating;

	system("CLS");
	cout << "What is the title of the movie?: ";
	cin.ignore();
	getline(cin, title);
	cout << "How long is the movie?: ";
	cin >> length;
	cout << "What is the rating of the movie (from IMDb)?: ";
	cin >> rating;

	movie.set_title(title);
	movie.set_length(length);
	movie.set_rating(rating);
	movie.set_was_watched(false);

	return movie;
}


Live_Event Menu::add_live_event() {
	Live_Event live_event;
	string title;
	int length, begin_hour, begin_minute;

	system("CLS");
	cout << "What is the title of the live event?: ";
	cin.ignore();
	getline(cin, title);
	cout << "How long is the live event?: ";
	cin >> length;
	cout << "On what hour will the show begin?: ";
	cin >> begin_hour;
	cout << "On what minute will the show begin?: ";
	cin >> begin_minute;

	live_event.set_title(title);
	live_event.set_length(length);
	live_event.set_begin_hour(begin_hour);
	live_event.set_begin_minute(begin_minute);
	live_event.set_was_watched(false);

	return live_event;
}


//EDITING SECTION


void Menu::edit_menu(Pool <TV_show>& shows_pool, Pool <Movie>& movies_pool, Pool <Live_Event>& events_pool) {
	int choose2;
	system("CLS");
	cout << "1. Edit show\n2. Edit movie\n3. Edit live show\n9. Go back\nEnter number: ";
	cin >> choose2;

	switch (choose2) {
	case 1:
		edit_show(shows_pool);
		break;

	case 2:
		edit_movie(movies_pool);
		break;

	case 3:
		edit_live_event(events_pool);
		break;
	}
}


void Menu::edit_show(Pool <TV_show>& shows_pool) {
	int choose;
	system("CLS");
	cout << "Which show do you want to edit?\n";
	for (int i = 0; i < shows_pool.pool.size(); i++) {
		cout << i << ". " << shows_pool.pool[i].get_title() << endl;
	}
	cout << "Enter numer: ";
	cin >> choose;

	TV_show& show = shows_pool.pool[choose];
	system("CLS");
	cout << "What do you wanna do?\n1. Change current episode \n2. Edit title \n3. Edit rating \n" <<
		"4. Edit length \n5. Edit number of episodes \n9. Exit \nEnter number: ";
	cin >> choose;
	system("CLS");

	switch (choose) {
	case 1:
		int viewed;
		cout << "How many episodes did you watch?: ";
		cin >> viewed;
		if (show.check_if_all_ep_watched(viewed)) {
			cout << "you have watched all episodes of this show";
			system("pause");
		}
		show.set_current_episode(show.get_current_episode() + viewed);
		break;

	case 2: {
		string title;
		cout << "What is the title of the show?: ";
		cin.ignore();
		getline(cin, title);
		show.set_title(title);
		break;
	}

	case 3:
		float rating;
		cout << "What is the rating of the show?: ";
		cin >> rating;
		show.set_rating(rating);
		break;

	case 4:
		int length;
		cout << "How long is one episode on average?: ";
		cin >> length;
		show.set_length(length);
		break;

	case 5:
		int number_of_episodes;
		cout << "How many episodes does this show have?: ";
		cin >> number_of_episodes;
		show.set_number_of_episodes(number_of_episodes);
		break;
	}
}


void Menu::edit_movie(Pool <Movie>& movies_pool) {
	int choose;
	system("CLS");
	cout << "Which movie do you want to edit?\n";
	for (int i = 0; i < movies_pool.pool.size(); i++) {
		cout << i << ". " << movies_pool.pool[i].get_title() << endl;
	}
	cout << "Enter numer: ";
	cin >> choose;

	Movie& movie = movies_pool.pool[choose];
	system("CLS");
	cout << "What do you wanna do?\n1. Mark movie as watched \n2. Edit title \n3. Edit rating \n" <<
		"4. Edit length\n9. Exit \nEnter number: ";
	cin >> choose;
	system("CLS");

	switch (choose) {
	case 1:
		int viewed;
		cout << "Did you watch the movie (1 for yes, 0 for no)?: ";
		cin >> viewed;
		if (viewed == 1) {
			movie.set_was_watched(true);
		}
		else {
			movie.set_was_watched(false);
		}		
		break;

	case 2: {
		string title;
		cout << "What is the title of the movie?: ";
		cin.ignore();
		getline(cin, title);
		movie.set_title(title);
		break;
	}

	case 3:
		float rating;
		cout << "What is the rating of the movie?: ";
		cin >> rating;
		movie.set_rating(rating);
		break;

	case 4:
		int length;
		cout << "How long is the movie?: ";
		cin >> length;
		movie.set_length(length);
		break;
	}
}


void Menu::edit_live_event(Pool <Live_Event>& events_pool) {
	int choose;
	system("CLS");
	cout << "Which live event do you want to edit?\n";
	for (int i = 0; i < events_pool.pool.size(); i++) {
		cout << i << ". " << events_pool.pool[i].get_title() << endl;
	}
	cout << "Enter numer: ";
	cin >> choose;

	Live_Event& live_event = events_pool.pool[choose];
	system("CLS");
	cout << "What do you wanna do?\n1. Mark live event as watched \n2. Edit title \n3. Edit length \n" <<
		"4. Edit begin hour\n5. Edit begin minute\n9. Exit \nEnter number: ";
	cin >> choose;
	system("CLS");

	switch (choose) {
	case 1:
		int viewed;
		cout << "Did you watch the movie (1 for yes, 0 for no)?: ";
		cin >> viewed;
		if (viewed == 1) {
			live_event.set_was_watched(true);
		}
		else {
			live_event.set_was_watched(false);
		}
		break;

	case 2: {
		string title;
		cout << "What is the title of the live_event?: ";
		cin.ignore();
		getline(cin, title);
		live_event.set_title(title);
		break;
	}

	case 3:
		int length;
		cout << "How long is the movie?: ";
		cin >> length;
		live_event.set_length(length);
		break;

	case 4:
		int begin_hour;
		cout << "On what hour will the show begin?: ";
		cin >> begin_hour;
		live_event.set_begin_hour(begin_hour);
		break;

	case 5:
		int begin_minute;
		cout << "On what minute will the show begin?: ";
		cin >> begin_minute;
		live_event.set_begin_minute(begin_minute);
		break;
	}
}


//DELETE SECION


void Menu::delete_menu(Pool <TV_show>& shows_pool, Pool <Movie>& movies_pool, Pool <Live_Event>& events_pool) {
	int choose;
	system("CLS");
	cout << "1. Delete show\n2. Delete movie\n3. Delete live show\n9. Go back\nEnter number: ";
	cin >> choose;

	switch (choose) {
	case 1:
		delete_show(shows_pool);
		break;

	case 2:
		delete_movie(movies_pool);
		break;

	case 3:
		delete_live_event(events_pool);
		break;
	}
}


void Menu::delete_show(Pool <TV_show>& shows_pool) {
	int choose;
	system("CLS");
	cout << "Which show do you want to delete?\n";
	for (int i = 0; i < shows_pool.pool.size(); i++) {
		cout << i << ". " << shows_pool.pool[i].get_title() << endl;
	}
	cout << "Enter numer: ";
	cin >> choose;

	shows_pool.pool.erase(shows_pool.pool.begin() + choose);
}


void Menu::delete_movie(Pool <Movie>& movies_pool) {
	int choose;
	system("CLS");
	cout << "Which movie do you want to delete?\n";
	for (int i = 0; i < movies_pool.pool.size(); i++) {
		cout << i << ". " << movies_pool.pool[i].get_title() << endl;
	}
	cout << "Enter numer: ";
	cin >> choose;

	movies_pool.pool.erase(movies_pool.pool.begin() + choose);
}


void Menu::delete_live_event(Pool <Live_Event>& events_pool) {
	int choose;
	system("CLS");
	cout << "Which live event do you want to delete?\n";
	for (int i = 0; i < events_pool.pool.size(); i++) {
		cout << i << ". " << events_pool.pool[i].get_title() << endl;
	}
	cout << "Enter numer: ";
	cin >> choose;

	events_pool.pool.erase(events_pool.pool.begin() + choose);
}


//SORTING SECTION


void Menu::sort_menu(Pool <TV_show>& shows_pool, Pool <Movie>& movies_pool) {
	int choose;
	system("CLS");
	cout << "What do you want to sort by rating?\n1. TV shows\n2. Movies\n9. Exit\nEnter number: ";
	cin >> choose;

	switch (choose) {
	case 1: {
		system("CLS");
		vector <TV_show> shows_pool_vector_cp = shows_pool.pool;
		sort(shows_pool_vector_cp.begin(), shows_pool_vector_cp.end());
		for (int i = 0; i < shows_pool_vector_cp.size(); i++) {
			cout << i + 1 << ". " << shows_pool_vector_cp[i].get_title() << " ocena " << shows_pool_vector_cp[i].get_rating() << endl;
		}
		system("pause");
		break;
	}
	case 2: {
		system("CLS");
		vector <Movie> movies_pool_vector_cp = movies_pool.pool;
		sort(movies_pool_vector_cp.begin(), movies_pool_vector_cp.end());
		for (int i = 0; i < movies_pool_vector_cp.size(); i++) {
			cout << i + 1 << ". " << movies_pool_vector_cp[i].get_title() << " ocena " << movies_pool_vector_cp[i].get_rating() << endl;
		}
		system("pause");
		break;
	}
	}	
}


//RECOMMENDING SECTION


void Menu::recommend(Pool <TV_show>& shows_pool, Pool <Movie>& movies_pool) {
	//Aplication recommend best rated not watched show and movie in database
	system("CLS");
	vector <TV_show> shows_pool_vector_cp = shows_pool.pool;
	vector <Movie> movies_pool_vector_cp = movies_pool.pool;

	for (int i = 0; i < shows_pool_vector_cp.size(); i++) {
		bool viewed = shows_pool_vector_cp[i].get_was_watched();
		if ( viewed == true) {
			shows_pool_vector_cp.erase(shows_pool_vector_cp.begin() + i);
		}
	}

	for (int i = 0; i < movies_pool_vector_cp.size(); i++) {
		bool viewed = movies_pool_vector_cp[i].get_was_watched();
		if (viewed == true) {
			movies_pool_vector_cp.erase(movies_pool_vector_cp.begin() + i);
		}
	}

	cout << "Recommended TV show is:\n\n";
	sort(shows_pool_vector_cp.begin(), shows_pool_vector_cp.end());	
	if (shows_pool_vector_cp.empty()) {
		cout << "\tPlease add shows to database.\n\n";
	}
	else {
		cout <<"\t" + shows_pool_vector_cp[0].get_title() + "\n\n";
	}

	cout << "Recommended Movie is:\n\n";
	sort(movies_pool_vector_cp.begin(), movies_pool_vector_cp.end());
	if (movies_pool_vector_cp.empty()) {
		cout << "\tPlease add movies to database.\n";
	}
	else {
		cout << "\t" + movies_pool_vector_cp[0].get_title() << endl;
	}

	system("pause");
}


//STATISTICS SECTION


void Menu::statistics(Pool <TV_show>& shows_pool, Pool <Movie>& movies_pool, Pool <Live_Event>& events_pool) {
	int shows_sum = 0, shows_ep_sum = 0, shows_watchtime_sum = 0;
	int movies_sum = 0, movies_watchtime_sum = 0;
	int live_events_sum = 0;

	for (int i = 0; i < shows_pool.pool.size(); i++) {
		if (shows_pool.pool[i].get_was_watched()) {
			shows_sum++;
		}
		shows_ep_sum += shows_pool.pool[i].get_current_episode();
		shows_watchtime_sum += shows_pool.pool[i].get_current_episode() * shows_pool.pool[i].get_length();
	}

	for (int i = 0; i < movies_pool.pool.size(); i++) {
		if (movies_pool.pool[i].get_was_watched()) {
			movies_sum++;
			movies_watchtime_sum += movies_pool.pool[i].get_length();
		}
	}

	for (int i = 0; i < events_pool.pool.size(); i++) {
		if (movies_pool.pool[i].get_was_watched()) {
			live_events_sum++;
		}
	}

	system("CLS");
	cout << "STATISTICS\n\nTV SHOWS\n\n TV shows watched: " << shows_sum << "\n Episodes watched: " << shows_ep_sum <<
		"\n Watchtime: " << shows_watchtime_sum << "\n\nMOVIES\n\n Movies watched: " << movies_sum << "\n Watchtime: " <<
		movies_watchtime_sum << "\n\nLIVE EVENTS\n\n Live events watched: " << live_events_sum << "\n\n";
	system("pause");
}