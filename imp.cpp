#include "game.h"
#include <iostream>
using namespace std;

bool game::setGame() {

	int t,d = 1, r = 0;
	bool c = true;


	while (r != 9) {

		if (r % 2 == 0)
		{
			while (d)
			{
				cout << "\n\t Please, enter a valid value for setting X _";
				cin >> t;
				d = checkV(t);
			}
			
			c = setting(t,d,r);
			if (c == false)
			{
				cout << "\t\tThe player number one is the winner\n";
				return 0;
			}
		}
		else
		{
			while (d)
			{
				cout << "\n\t  Please, enter a valid value for setting O _";
				cin >> t;
				d = checkV(t);
			}

			c = setting(t,d,r);
			if (c == false)
			{
				cout << "\t\tThe player number two is the winner\n";
				return 0;
			}
		}

		++r;
	}

	cout << "\n\t\tDraw";
	return 0;
}
void game::printPlane() {

	for (size_t i = 0; i < 3; ++i)
	{
		cout << "               ";
		for (size_t j = 0; j < 3; ++j)
		{
			cout << plane[i][j] << "   ";
		}
		cout << "\n\n";
	}

}
bool game::checkV(int d) {

	for (size_t i = 0; i < 9; ++i)
	{
		if (d == oldValue[i] || d > 9 || d < 1)
		{
			cout << "\n\t  " << d << " is not valid value!!\n";
			return 1;
		}
	}
	return 0;
}
int game::swtch(int d) {

	if (d == 0)
		return 2;
	return d - 1;

}
bool game::check() {

	int c = 0;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if ((plane[i][j] == plane[i][j + 1]) && plane[i][j] != '+')
				++c;
			else
				break;
		}
		if (c == 2)
			return false;
		c = 0;
	}

	for (int j = 0; j < 3; ++j)
	{
		for (int i = 0; i < 2; ++i)
		{
			if (plane[i][j] == plane[i + 1][j] && plane[i][j] != '+')
				++c;
			else
				break;
		}
		if (c == 2)
			return false;
		c = 0;
	}


	if (plane[0][0] != '+' && plane[0][0] == plane[1][1] && plane[1][1] == plane[2][2])
		return false;

	if (plane[0][2] != '+' && plane[0][2] == plane[1][1] && plane[1][1] == plane[2][0])
		return false;

	return true;
}
bool game::setting(int t, int &d, int r) {
	oldValue[r] = t;
	d = t % 3;
	t = t - d;
	if (d)
		t = t / 3;
	else
		t = t / 3 - 1;

	d = swtch(d);
	if(r % 2 == 0)
		plane[t][d] = 'X';
	else
		plane[t][d] = 'O';
	cout << "\n\n\n";
	printPlane();
	d = 1;
	return check();
}
game::game() {

	for (size_t i = 0; i < 3; ++i)
		for (size_t j = 0; j < 3; j++)
			plane[i][j] = '+';

	for (size_t i = 0; i < 9; ++i)
		oldValue[i] = 0;
}
game::~game() {

	cout << "\n\nThe end of the game\n\n";
}