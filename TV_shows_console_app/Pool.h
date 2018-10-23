#pragma once
#include "TV_show.h"
#include <string>
#include <iostream>

class Pool {
private:
	TV_show shows[100];
	int current_index;
public:
	void add_show();
};