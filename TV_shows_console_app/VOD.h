#pragma once
#include <string>

class VOD {
private:
	float rating;
	bool was_watched;
	std::string title;
	int length;
public:
	void set_rating(float r) { rating = r; }
	float get_rating() { return rating; }
	void set_was_watched(bool b) { was_watched = b; }
	bool get_was_watched() { return was_watched; }
	void set_title(std::string t) { title = t; }
	std::string get_title() { return title; }
	void set_length(int l) { length = l; }
	int get_length() { return length; }
};
