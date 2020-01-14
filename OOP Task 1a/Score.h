#pragma once
#include"Constants.h"

class Score
{
public:
	Score();
	~Score();
	int get_amount();
	void update_amount(int amount);

private:
	int amount;
};

