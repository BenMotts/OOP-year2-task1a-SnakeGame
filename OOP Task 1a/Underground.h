#pragma once

#include <cassert>
#include <vector>

#include "constants.h"
#include "FixedGridItem.h"

using namespace std;

class Hole : public FixedItem
{
public:
	// constructors
	Hole();
	Hole(int x, int y);



private:

};

class Underground
{
private:
	vector<Hole> holes;
public:
	Underground();
	bool is_hole_at_position(const int& no, const int& x, const int& y) const;
	void set_hole_no_at_position(const int& no, int x, int y);
	bool is_valid_hole_number(const int& n) const;
	int get_hole_count() const;
	char get_hole_symbol(const int& no) const;
	int get_hole_x_at_position(const int& no) const;
	int get_hole_y_at_position(const int& y) const;
	int get_random_hole_number(const int& x, const int& y) const;
};