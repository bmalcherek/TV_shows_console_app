#include "User.h"
#include "VOD.h"
#include "TV_show.h"
#include <iostream>
#include <string>

int main() {
	User user;
	TV_show show;
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
	std::cout << "Your name is: " << n << ", your favourite genre is: " << genre << " and you want to watch TV " << t << " minutes daily\n";
	system("pause");
	return 0;
}