#include "Pool.h"
using namespace std;

void Pool::add_show() {
	TV_show show;
	string title;
	float rating;
	int length, number_of_episodes;

	cout << "What's the title of the show";
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
}