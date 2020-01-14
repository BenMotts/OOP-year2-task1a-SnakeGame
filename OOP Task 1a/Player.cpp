#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

string Player::get_name()
{
	return name;
}

int Player::get_score()
{
	return score.get_amount();
}
void Player::update_score(int amount)
{
	score.update_amount(amount);
}
void Player::update_name(string na1e)
{
	name = na1e;
}