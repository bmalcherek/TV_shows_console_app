#pragma once
#include "Watchable_element.h"


class Movie : public Watchable_Element {

private:
	float rating;

public:
	void set_rating(float r) { rating = r; }
	float get_rating() { return rating; }
};