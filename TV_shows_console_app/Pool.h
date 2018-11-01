#pragma once
#include "TV_show.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;


template <class T>
class Pool {

private:
	
public:
	vector <T> pool;
	Pool & operator+= (T t) {
		pool.push_back(t);
		return *this;
	}
};