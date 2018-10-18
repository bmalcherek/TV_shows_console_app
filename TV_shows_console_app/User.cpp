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

