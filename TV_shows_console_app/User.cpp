#include "User.h"
#include <iostream>

void User::set_name(std::string n) {
	name = n;
}

std::string User::get_name() {
	return name;
}

void User::set_favourite_genre(std::string genre) {
	favourite_genre = genre;
}

std::string User::get_favourite_genre() {
	return favourite_genre;
}

void User::set_wanted_daily_watch_time(int t){
	wanted_daily_watch_time = t;
}

int User::get_wanted_daily_watch_time() {
	return wanted_daily_watch_time;
}

int main() {
	User user;
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
	std::cout << "Your name is: " << n << ", your favourite genre is: " << genre << " and you want to watch TV " << t << " minutes daily";
	system("pause");
	return 0;
}