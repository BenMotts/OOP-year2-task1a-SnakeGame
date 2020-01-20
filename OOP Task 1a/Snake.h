#pragma once

#include "Mouse.h"
#include "RandomNumberGenerator.h"
class BodyPart;
class Snake {
public:
	Snake();
	~Snake();

	vector<BodyPart> snakeBody;
	bool is_at_position(const int& x, const int& y);
	bool has_caught_mouse();
	void spot_mouse(Mouse* p_mouse);
	void chase_mouse();
	void set_direction(int& dx, int& dy);
	void position_at_random();
	void update_position(const int& dx, const int& dy);
	char get_symbol(const int& i) const;
	int get_x() const;
	int get_y() const;
	void move_tail(const int& dx, const int& dy);
	int returnCounter();
	void update_counter(int counter);

private:

	int counter;
	Mouse* p_mouse;
	RandomNumberGenerator rng;

};

class BodyPart {
private:
	int x;
	int y;
	char symbol;

public:
	BodyPart(char);
	int get_x() const;
	int get_y() const;
	void set_x(const int&);
	void set_y(const int&);
	void move_x(const int&);
	void move_y(const int&);
	char get_symbol() const;
};