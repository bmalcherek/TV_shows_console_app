#include "User.h"
#include "VOD.h"
#include "Menu.h"
#include "Pool.h"
#include "TV_show.h"
#include <iostream>
#include <string>

int main() {
	Pool pool;
	Menu menu;
	pool.initialize();
	menu.main_menu(pool);
	system("pause");
	return 0;
}