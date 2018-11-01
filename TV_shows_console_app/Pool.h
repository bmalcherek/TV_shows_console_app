#pragma once
#include "TV_show.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*class Pool {
private:	
	int current_index;
public:
	TV_show shows[100];
	void initialize() { current_index = 0; }
	int get_current_index() { return current_index; }
	void set_current_index(int i) { current_index = i; }
	friend class Menu;
};*/


template <class T>
class Pool {

private:
	vector <T> pool;

public:
	/*Pool& operator++ (T t){
		pool.push_back(t);
	}*/
};