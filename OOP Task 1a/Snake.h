#pragma once

#include "Mouse.h"
#include "RandomNumberGenerator.h"

class Snake {
public:
	Snake();
	~Snake();
	bool is_at_position(const int& x, const int& y);
	bool has_caught_mouse();
	void spot_mouse(Mouse* p_mouse);
	void chase_mouse();
	void set_direction(int& dx, int& dy);
	void position_at_random();
	void update_position(const int& dx, const int& dy);
	char get_symbol() const;
	int get_x() const;
	int get_y() const;

private:
	char symbol;
	int x;
	int y;
	Mouse* p_mouse;
	RandomNumberGenerator rng;
};