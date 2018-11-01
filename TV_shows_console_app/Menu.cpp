#include "Menu.h"
using namespace std;


void Menu::main_menu() {
	int choose, choose2;
	system("CLS");
	cout << "Hi, what would you like to do?\n1. Add show/movie/live show\n" <<
		"2. Edit show/movie/live show\n9. Exit\nEnter number: ";
	cin >> choose;
	system("CLS");
	switch (choose) {
	case 1: {
		cout << "1. Add show\n 2. Add movie\n 3. Add live show\n 9. Go back";
		cin >> choose2;
		switch (choose2) {
		case 1:
			break;
		}
		break;
	}
	case 2: {
		cout << "1. Edit show\n 2. Edit movie\n 3. Edit live show\n 9. Go back";
		cin >> choose2;
		switch (choose2) {
		case 1:
			break;
		}
		break;
	}
	}
}
