#pragma once
class game {

	int oldValue[9];
	char plane[3][3];


public:
	bool setGame();
	void printPlane();
	int swtch(int);
	bool checkV(int);
	bool check();
	bool setting(int, int&, int);
	game();
	~game();

};