#pragma once
#include <string>

using namespace std;


class Watchable_Element {

private:
	int length;
	bool was_watched;
	string title;

public:
	void set_length(int l) { length = l; }
	int get_length() { return length; }
	void set_was_watched(bool b) { was_watched = b; }
	bool get_was_watched() { return was_watched; }
	void set_title(string t) { title = t; }
	string get_title() { return title; }
};