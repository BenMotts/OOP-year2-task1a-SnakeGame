#include "Snake.h"
#include "Constants.h"
#include "Mouse.h"
#include "RandomNumberGenerator.h"

Snake::Snake() : symbol(SNAKEHEAD), p_mouse(nullptr)
{
	position_at_random();
}

Snake::~Snake()
{

}

bool Snake::is_at_position(const int& x, const int& y)
{
	return (this->x == x) && (this->y == y);
}

bool Snake::has_caught_mouse()
{
	return is_at_position(p_mouse->get_x(), p_mouse->get_y());
}

void Snake::spot_mouse(Mouse* p_mouse)
{
	// pre-condition: the mouse needs to exist 
	assert(p_mouse != nullptr);

	this->p_mouse = p_mouse;
}

void Snake::chase_mouse()
{
	int snake_dx, snake_dy;

	//identify direction of travel
	set_direction(snake_dx, snake_dy);

	//go in that direction
	update_position(snake_dx, snake_dy);
}

void Snake::set_direction(int& dx, int& dy)
{
	// pre-condition: The snake needs to know where the mouse is 
	assert(p_mouse != nullptr);

	// assume snake only moves when necessary
	dx = 0; dy = 0;

	// update coordinate if necessary
	if (x < p_mouse->get_x())         // if snake on left of mouse
		dx = 1;                        // snake should move right
	else if (x > p_mouse->get_x())    // if snake on left of mouse
		dx = -1;						       // snake should move left

	if (y < p_mouse->get_y())         // if snake is above mouse
		dy = 1;                        // snake should move down
	else if (y > p_mouse->get_y())    // if snake is below mouse
		dy = -1;						       // snake should move up
}

void Snake::update_position(const int& dx, const int& dy)
{
	x += dx;
	y += dy;
}

void Snake::position_at_random()
{
	// WARNING: this may place on top of other things

	x = rng.get_random_value(SIZE);
	y = rng.get_random_value(SIZE);
}

char Snake::get_symbol() const {
	return symbol;
}

int Snake::get_x() const {
	return x;
}

int Snake::get_y() const {
	return y;
}
