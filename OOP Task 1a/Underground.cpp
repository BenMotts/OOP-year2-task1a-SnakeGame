#include "Underground.h"



Hole::Hole()
{

}

Hole::Hole(int x, int y) : FixedItem(x, y)
{
	symbol = HOLE;
}

// number of holes in underground
static const int MAXHOLES(3);

Underground::Underground() : holes(MAXHOLES)
{
}


void Underground::set_hole_no_at_position(const int& no, int x, int y)
{
	// pre-condition: valid hole number
	assert(is_valid_hole_number(no));

	Hole h(x, y);

	switch (no)
	{
	case 0: holes.at(0) = h; break;
	case 1: holes.at(1) = h; break;
	case 2: holes.at(2) = h; break;
	}
}

bool Underground::is_valid_hole_number(const int& no) const
{
	return no >= 0 && no < (int)holes.size();
}

bool Underground::is_hole_at_position(const int& no, const int& x, const int& y) const {
	// pre-condition: valid hole number
	assert(is_valid_hole_number(no));

	return holes.at(no).is_at_position(x, y);

}

int Underground::get_hole_count() const {
	return holes.size();
}

char Underground::get_hole_symbol(const int& no) const {
	// pre-condition: valid hole number
	assert(is_valid_hole_number(no));

	return holes.at(no).get_symbol();
}

int Underground::get_hole_x_at_position(const int& no) const {
	// pre-condition: valid hole number
	assert(is_valid_hole_number(no));


	return holes.at(no).get_x();
}

int Underground::get_hole_y_at_position(const int& no) const {
	// pre-condition: valid hole number
	assert(is_valid_hole_number(no));

	return holes.at(no).get_y();
}

