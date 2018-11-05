#include "Menu.h"
using namespace std;


void Menu::main_menu(Pool <TV_show>& shows_pool, Pool <Movie>& movies_pool, Pool <Live_Event>& events_pool) {
	int choose;
	system("CLS");
	cout << "Hi, what would you like to do?\n1. Add show/movie/live show\n" <<
		"2. Edit show/movie/live show\n3. Delete show/movie/live show\n4. Show by rating\n9. Exit\nEnter number: ";
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
	case 9:
		exit(0);
	}
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
		vector <TV_show> shows_pool_vector_cp = shows_pool.pool;
		sort(shows_pool_vector_cp.begin(), shows_pool_vector_cp.end());
		for (int i = 0; i < shows_pool_vector_cp.size(); i++) {
			cout << i + 1 << ". " << shows_pool_vector_cp[i].get_title() << " ocena " << shows_pool_vector_cp[i].get_rating() << endl;
		}
		system("pause");
	}
	case 2: {
		vector <Movie> movies_pool_vector_cp = movies_pool.pool;
		sort(movies_pool_vector_cp.begin(), movies_pool_vector_cp.end());
		for (int i = 0; i < movies_pool_vector_cp.size(); i++) {
			cout << i + 1 << ". " << movies_pool_vector_cp[i].get_title() << " ocena " << movies_pool_vector_cp[i].get_rating() << endl;
		}
		system("pause");
	}
	}	
}