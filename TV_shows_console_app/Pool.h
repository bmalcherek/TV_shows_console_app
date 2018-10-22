#pragma once
#include "TV_show.h"

class Pool {
private:
	TV_show shows[100];
	int current_index;
public:
	void add_show(TV_show);
};