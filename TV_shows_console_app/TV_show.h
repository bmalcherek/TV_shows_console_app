#pragma once
#include <string>
#include "Watchable_Element.h"
#include "Pool.h"

using namespace std;


class TV_show : public Watchable_Element {

private:
	int number_of_episodes, current_episode;
	float rating;

public:
	void set_number_of_episodes(int n) { number_of_episodes = n; }
	int get_number_of_episodes() { return number_of_episodes; }
	void set_current_episode(int c) { current_episode = c; }
	int get_current_episode() { return current_episode; }
	void set_rating(float r) { rating = r; }
	float get_rating() { return rating; }
	bool operator< (const TV_show& other) const { return rating > other.rating; } //https://stackoverflow.com/questions/9706517/sort-a-vector-of-objects-by-an-objects-attribute
	bool check_if_all_ep_watched(int);
};