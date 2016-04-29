#include "Card.h"
#include <string>
#include <iostream>

using namespace std;

int Card::counter=0; //club , heart , diamond, spade

Card::Card()
{
	switch(counter/13)
	{
		case 0: _colour="club";break;

		case 1: _colour="heart"; break;

		case 2: _colour="diamond"; break;

		case 3: _colour="spade"; break;

		default: break;
	};

	switch(counter%13)
	{
		case 0: _name="2"; counter++; _value=0; break;
		case 1: _name="3"; counter++; _value=1; break;
		case 2: _name="4"; counter++; _value=2; break;
		case 3: _name="5"; counter++; _value=3; break;
		case 4: _name="6"; counter++; _value=4; break;
		case 5: _name="7"; counter++; _value=5; break;
		case 6: _name="8"; counter++; _value=6; break;
		case 7: _name="9"; counter++; _value=7; break;
		case 8: _name="10"; counter++; _value=8; break;
		case 9: _name="Jack"; counter++; _value=9; break;
		case 10: _name="Queen"; counter++; _value=10; break;
		case 11: _name="King"; counter++; _value=11; break;
		case 12: _name="Ace"; counter++; _value=12; break;
	}

}

string Card::display()
{
	return string(_name)+string(" ")+string(_colour);
}
