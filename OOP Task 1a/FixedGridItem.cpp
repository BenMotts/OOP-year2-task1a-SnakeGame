#include "FixedGridItem.h"

FixedItem::FixedItem() : x(0), y(0)
{

}


FixedItem::~FixedItem()
{
}

FixedItem::FixedItem(int x, int y):x(x),y(y)
{

}

int FixedItem::get_x()const
{
	return x;
}

int FixedItem::get_y()const
{
	return y;
}

bool FixedItem::is_at_position(const int & x, const int &) const
{
	return (this->x == x) && (this->y == y);
}


