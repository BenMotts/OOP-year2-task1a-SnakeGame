#pragma once
#include "Constants.h"
#include "Mouse.h"

using namespace std;

class Nut {

     public:
		 Nut();
		 void spot_mouse(Mouse* p_mouse);
		 int get_x();
		 int get_y();
		 char get_symbol();
		 bool has_been_collected();
		 bool is_at_position(const int& x, const int& y);
		 void disappear();
		 void respawn_nut();

		 

     private:
		 int x;
		 int y;
		 char symbol;
		 bool collected;
		 Mouse* pointer_mouse;


};