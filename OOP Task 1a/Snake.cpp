#include "Snake.h"
#include "Constants.h"
#include "Mouse.h"
#include "RandomNumberGenerator.h"

Snake::Snake() : p_mouse(nullptr)
{

	for (int i(0); i < 4; ++i) {
		if (i == 0) {
			BodyPart snakePart(SNAKEHEAD);
			snakeBody.push_back(snakePart);
		}
		else {
			BodyPart snakePart(SNAKEBODY);
			snakeBody.push_back(snakePart);
		}
	}
	position_at_random();
	counter = 0;
}

Snake::~Snake()
{

}

bool Snake::is_at_position(const int& x, const int& y)
{
	return (snakeBody.at(0).get_x() == x) && (snakeBody.at(0).get_y() == y);
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
	if (snakeBody.at(0).get_x() < p_mouse->get_x())         // if snake on left of mouse
		dx = 1;                        // snake should move right
	else if (snakeBody.at(0).get_x() > p_mouse->get_x())    // if snake on left of mouse
		dx = -1;						       // snake should move left
	if (snakeBody.at(0).get_y() < p_mouse->get_y())         // if snake is above mouse
		dy = 1;                        // snake should move down
	else if (snakeBody.at(0).get_y() > p_mouse->get_y())    // if snake is below mouse
		dy = -1;						       // snake should move up
}

void Snake::update_position(const int& dx, const int& dy)
{
	counter++;
	move_tail(dx, dy);
	snakeBody.at(0).move_x(dx);
	snakeBody.at(0).move_y(dy);
}

void Snake::position_at_random()
{
	// WARNING: this may place on top of other things
	snakeBody.at(0).set_x(rng.get_random_value(SIZE));
	snakeBody.at(0).set_y(rng.get_random_value(SIZE));
	for (int i(1); i < snakeBody.size(); ++i) {
		snakeBody.at(i).set_x(0);
		snakeBody.at(i).set_y(0);
	}
}

char Snake::get_symbol(const int& i) const {
	return snakeBody.at(i).get_symbol();
}

int Snake::get_x() const {
	return snakeBody.at(0).get_x();
}

int Snake::get_y() const {
	return snakeBody.at(0).get_y();
}
void Snake::move_tail(const int& dx, const int& dy)
{
	if (counter == 1) {
		snakeBody.at(1).set_x(snakeBody.at(0).get_x());
		snakeBody.at(1).set_y(snakeBody.at(0).get_y());
	}
	else if (counter == 2) {
		snakeBody.at(2).set_x(snakeBody.at(1).get_x());
		snakeBody.at(2).set_y(snakeBody.at(1).get_y());
		snakeBody.at(1).set_x(snakeBody.at(0).get_x());
		snakeBody.at(1).set_y(snakeBody.at(0).get_y());
	}
	else 
		for (int i(snakeBody.size() - 1); i > 0; --i) {
			snakeBody.at(i).set_x(snakeBody.at(i - 1).get_x());
			snakeBody.at(i).set_y(snakeBody.at(i - 1).get_y());
		}

}

int Snake::returnCounter()
{
	return counter;
}

void Snake::update_counter(int counter)
{
	this->counter = counter;
}

BodyPart::BodyPart(char symbol) : symbol(symbol) {
	x = 0;
	y = 0;
}

int BodyPart::get_x() const {
	return x;
}

int BodyPart::get_y() const {
	return y;
}

void BodyPart::set_x(const int& x) {
	this->x = x;
}

void BodyPart::set_y(const int& y) {
	this->y = y;
}

void BodyPart::move_x(const int& amt) {
	x += amt;
}

void BodyPart::move_y(const int& amt) {
	y += amt;
}

char BodyPart::get_symbol() const {
	return symbol;
}