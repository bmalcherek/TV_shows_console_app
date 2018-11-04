#pragma once
#include "Watchable_element.h"


class Movie : public Watchable_Element {

private:
	float rating;

public:
	void set_rating(float r) { rating = r; }
	float get_rating() { return rating; }
	bool operator< (const Movie& other) const { return rating < other.rating; } //https://stackoverflow.com/questions/9706517/sort-a-vector-of-objects-by-an-objects-attribute

};