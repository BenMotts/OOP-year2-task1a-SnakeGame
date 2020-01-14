#include "Score.h"

Score::Score()
{
	amount = 0;
}

Score::~Score()
{
}

int Score::get_amount()
{
	return amount;
}
void Score::update_amount(int amount)
{
	this->amount += amount;
}