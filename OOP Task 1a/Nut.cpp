#include "Nut.h"


Nut::Nut():pointer_mouse(nullptr)
{
	respawn_nut();
}

void Nut::spot_mouse(Mouse* p_mouse)
{
	assert(p_mouse != nullptr);

	this->pointer_mouse = p_mouse;
}

char Nut::get_symbol()
{
	return symbol;
}
bool Nut::has_been_collected()
{
	if (is_at_position(pointer_mouse->get_x(), pointer_mouse->get_y()) == true)
		collected = true;
	return collected;
}

void Nut::disappear()
{
	symbol = FREECELL;
}
void Nut::respawn_nut()
{
	symbol = NUT;
 	x = rng.get_random_value(SIZE);
	y = rng.get_random_value(SIZE);
	collected = false;
}


