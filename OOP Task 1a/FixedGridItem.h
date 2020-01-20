#pragma once
#include "GridItem.h"

using namespace std;

class FixedItem :public GridItem
{
public:
	FixedItem();
	~FixedItem();
	FixedItem(int x, int y);
	int get_x()const;
	int get_y()const;
	bool is_at_position(const int& x, const int&) const;

protected:
	const int x;
	const int y;

};

