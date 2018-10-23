#include "User.h"
#include "VOD.h"
#include "Pool.h"
#include "TV_show.h"
#include <iostream>
#include <string>

int main() {
	Pool pool;
	pool.initialize();
	pool.add_show();
	pool.edit_show();
	//system("CLS");
	//system("CLS");

	/*User user;
	TV_show show;
	show.set_current_episode(1);
	show.set_length(20);
	show.set_number_of_episodes(20);
	show.set_rating(7.8);
	show.set_title("Friends");
	show.set_was_watched(false);
	std::string n, genre;
	int t;
	std::cout << "What's your name?: ";
	std::getline(std::cin, n);
	std::cout << "What's your favourite genre?: ";
	std::getline(std::cin, genre);
	std::cout << "How much time do you want to spend to watch movies?: ";
	std::cin >> t;
	user.set_name(n);
	user.set_favourite_genre(genre);
	user.set_wanted_daily_watch_time(t);
	n = user.get_name();
	genre = user.get_favourite_genre();
	t = user.get_wanted_daily_watch_time();
	std::cout << "Your name is: " << n << ", your favourite genre is: " << genre << " and you want to watch TV " << t << " minutes daily\n";*/
	system("pause");
	return 0;
}