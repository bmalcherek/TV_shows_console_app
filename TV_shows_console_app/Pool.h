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
	void edit_show();
	void initialize() { current_index = 0; }
	void edit_show_menu(TV_show&);
};