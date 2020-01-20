#include "GridItem.h"
#include "MovableGridItem.h"

MovableGridItem::MovableGridItem()
{
}

MovableGridItem::~MovableGridItem()
{
}

int MovableGridItem::get_x()
{
	return x;
}

int MovableGridItem::get_y()
{
	return y;
}

bool MovableGridItem::is_at_position(const int & x, const int & y)
{
	return (this->x == x) && (this->y == y);
}



void MovableGridItem::reset_position(int x, int y)
{
	this->x = x;
	this->y = y;
}

void MovableGridItem::update_position(int dx, int dy)
{
	x += dx;
	y += dy;
}
