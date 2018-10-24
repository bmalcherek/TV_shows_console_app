#include "Menu.h"
using namespace std;


void Menu::main_menu(Pool& pool) {
	int choose, choose2;
	system("CLS");
	cout << "Hi, what would you like to do?\n1. Add show/movie/live show\n" <<
		"2. Edit show/movie/live show\n9. Exit\nEnter number: ";
	cin >> choose;
	system("CLS");
	switch (choose) {
	case 1: {
		cout << "1. Add show\n 2. Add movie\n 3. Add live show\n 9. Go back";
		cin >> choose2;
		switch (choose2) {
		case 1:
			add_show(pool);
			break;
		}
		break;
	}
	case 2: {
		cout << "1. Edit show\n 2. Edit movie\n 3. Edit live show\n 9. Go back";
		cin >> choose2;
		switch (choose2) {
		case 1:
			edit_show(pool);
			break;
		}
		break;
	}
	}
	main_menu(pool);
}


void Menu::add_show(Pool& pool) {
	TV_show show;
	string title;
	float rating;
	int length, number_of_episodes;
	//int current_index = pool.get_current_index();

	cout << "What's the title of the show?: ";
	cin.ignore();
	getline(std::cin, title);
	cout << "How good is the show (from IMDb)?: ";
	cin >> rating;
	cout << "How long is one episode on average?: ";
	cin >> length;
	cout << "How many episodes does this show have?: ";
	cin >> number_of_episodes;	

	show.set_current_episode(0);
	show.set_length(length);
	show.set_number_of_episodes(number_of_episodes);
	show.set_rating(rating);
	show.set_title(title);
	show.set_was_watched(false);
	show.set_index(pool.current_index);

	pool.shows[pool.current_index] = show;
	pool.current_index++;
	system("CLS");
}


void Menu::edit_show_menu(Pool& pool, TV_show& show) {
	int choose;
	system("CLS");
	cout << "What do you wanna do?\n1. Change current episode \n2. Edit title \n3. Edit rating \n" <<
		"4. Edit length \n5. Edit number of episodes \n6. Exit \nEnter number: ";
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
	//edit_show_menu(show);
}


void Menu::edit_show(Pool& pool) {
	int index;
	system("CLS");
	cout << "Which show do you wanna edit?: \n";
	for (int i = 0; i < pool.get_current_index(); i++) {
		cout << i << ". " << pool.shows[i].get_title() << endl;
	}
	cout << "Enter number of show: ";
	cin >> index;
	TV_show& show = pool.shows[index];
	edit_show_menu(pool, show);
}