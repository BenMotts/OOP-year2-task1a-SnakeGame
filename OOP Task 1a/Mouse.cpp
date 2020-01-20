#include "Mouse.h"

Mouse::Mouse() : symbol(MOUSE), x(0), y(0), alive(true), escaped(false), mouse_dx(0), mouse_dy(0)
{
	initialise_position();
}

int Mouse::get_x() const
{
	return x;
}

int Mouse::get_y() const
{
	return y;
}

char Mouse::get_symbol() const
{
	return symbol;
}

bool Mouse::is_at_position(const int& x, const int& y)
{
	return this->x == x && this->y == y;
}

bool Mouse::is_alive() const
{
	return alive;
}

bool Mouse::has_escaped() const
{
	return escaped;
}

void Mouse::initialise_position() {
	x = rng.get_random_value(SIZE);
	y = rng.get_random_value(SIZE);
}

bool Mouse::has_reached_a_hole(Underground ug)
{
	
	for (int h_no = 0; h_no < (int)ug.get_hole_count(); ++h_no)
		if (is_at_position(ug.get_hole_x_at_position(h_no), ug.get_hole_y_at_position(h_no)))
			return true;

	return false;
}

void Mouse::die()
{
	alive = false;
}

void Mouse::escape_into_hole()
{
	escaped = true;
}

void Mouse::scamper(const int& key)
{
	switch (key)
	{
	case KEY_LEFT:
		mouse_dx = -1;
		mouse_dy = 0;
		break;
	case KEY_RIGHT:
		mouse_dx = +1;
		mouse_dy = 0;
		break;
	case KEY_UP:
		mouse_dx = 0;
		mouse_dy = -1;
		break;
	case KEY_DOWN:
		mouse_dx = 0;
		mouse_dy = +1;
		break;
	default:
		// not a key we care about, so do nothing
		break;
	}

	// update mouse coordinates if move is possible
	if (((x + mouse_dx) >= 1) && ((x + mouse_dx) <= SIZE) && ((y + mouse_dy) >= 1) && ((y + mouse_dy) <= SIZE))
	{
		update_position(mouse_dx, mouse_dy);
	}
}


void Mouse::update_position(const int& dx, const int& dy)
{
	x += dx;
	y += dy;
}

void Mouse::respawn_mouse()
{
	x = 0;
	y = 0;
	initialise_position();

	symbol = MOUSE;
	alive = true;
	escaped = false;
}
