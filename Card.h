#pragma once
#include <string>

using namespace std;

class Card
{
private:
	int _value;
	string _name;
	string _colour;
	static int counter;

public:
	Card();
	string display();
	int value() {return _value;};

};
