#pragma once

#include "Constants.h"
#include "Score.h"
#include <string>

using namespace std;

class Player
{
public:
	Player();
	~Player();

	string get_name();
	int get_score();
	void update_score(int amount);
	void update_name(string name);

private:
	string name;
	Score score;

};

