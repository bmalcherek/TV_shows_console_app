#pragma once
#include <string>

using namespace std;


class BadValueException {

private:
	string message;
	int errorCode;

public:
	BadValueException(string m) { message = m; }
	string get_message() { return message; }
	int get_error_code() { return errorCode; }
	void set_error_code(int e) { errorCode = e; }
};