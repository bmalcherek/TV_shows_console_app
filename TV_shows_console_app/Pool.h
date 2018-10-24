#pragma once
#include "TV_show.h"
#include <string>
#include <iostream>
#include "Menu.h"

class Pool {
private:	
	int current_index;
public:
	TV_show shows[100];
	void initialize() { current_index = 0; }
	int get_current_index() { return current_index; }
	friend class Menu;
};