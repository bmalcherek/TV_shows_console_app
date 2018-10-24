#pragma once
#include <string>
#include <iostream>
#include "Pool.h"
#include "TV_show.h"
#include "VOD.h"


class Menu {
public:
	void main_menu(Pool&);
	void add_show(Pool&);
	void edit_show(Pool&);
	void edit_show_menu(Pool&, TV_show&);
};