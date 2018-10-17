#pragma once
#include <string>

class User {
private:
	std::string name;
	std::string favourite_genre;
	int wanted_daily_watch_time;
public:
	void set_name(std::string);
	std::string get_name();
	void set_favourite_genre(std::string);
	std::string get_favourite_genre();
	void set_wanted_daily_watch_time(int);
	int get_wanted_daily_watch_time();
};