#include "Pool.h"
using namespace std;


void Pool::add_show() {
	TV_show show;
	string title;
	float rating;
	int length, number_of_episodes;

	cout << "What's the title of the show?: ";
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
	show.set_index(current_index);

	shows[current_index] = show;
	current_index++;
	system("CLS");
}


void Pool::edit_show_menu(TV_show& show) {
	int choose;
	system("CLS");
	cout << "What do you wanna do?\n 1. Change current episode \n 2. Edit title \n 3. Edit rating \n " <<
		"4. Edit length \n 5. Edit number of episodes \n 6. Exit \n Enter number: ";
	cin >> choose;
	system("CLS");

	switch (choose) {
	case 1:
		int viewed;
		cout << "How many episodes did you watch?: ";
		cin >> viewed;
		show.set_current_episode(show.get_current_episode() + viewed);
	case 2: {
		string title;
		cout << "What is the title of the show?: ";
		getline(cin, title);
		show.set_title(title);
	}
	case 3:
		float rating;
		cout << "What is the rating of the show?: ";
		cin >> rating;
		show.set_rating(rating);
	case 4:
		int length;
		cout << "How long is one episode on average?: ";
		cin >> length;
		show.set_length(length);
	case 5:
		int number_of_episodes;
		cout << "How many episodes does this show have?: ";
		cin >> number_of_episodes;
		show.set_number_of_episodes(number_of_episodes);
	}
	//edit_show_menu(show);
}


void Pool::edit_show() {
	int index;
	cout << "Which show do you wanna edit?: \n";
	for (int i = 0; i < current_index; i++) {
		cout << i << ". " << shows[i].get_title() << endl;
	}
	cout << "Enter number of show: ";
	cin >> index;
	TV_show show = shows[index];
	edit_show_menu(show);
}