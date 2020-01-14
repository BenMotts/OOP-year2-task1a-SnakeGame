#pragma once

#include "Mouse.h"
#include "RandomNumberGenerator.h"

class Snake {
public:
	Snake();
	~Snake();
	struct snakeBodyParts {
		char bodyPart1;
		char bodyPart2;
		char bodyPart3;

		int bodyPart1X;
		int bodyPart1Y;
		int bodyPart2X;
		int bodyPart2Y;
		int bodyPart3X;
		int bodyPart3Y;

	};
	vector<snakeBodyParts>bigSnakeBody;
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
	void move_tail(const int& dx, const int& dy);
	int returnCounter();


private:

	char symbol;
	int counter;
	int x;
	int y;
	int bodyX;
	int bodyY;
	Mouse* p_mouse;
	RandomNumberGenerator rng;
};