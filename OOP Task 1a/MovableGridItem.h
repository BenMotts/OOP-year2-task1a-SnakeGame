#pragma once
#include "GridItem.h"


using namespace std;

class MovableGridItem:public GridItem
{
public:
	MovableGridItem();
	~MovableGridItem();
	int get_x();
	int get_y();
	bool is_at_position(const int& x, const int& y);
	void reset_position(int x, int y);
	void update_position(int dx, int dy);

protected:	
	int x;
	int y;
};

