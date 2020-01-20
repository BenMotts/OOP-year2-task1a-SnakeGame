#pragma once
#include "Constants.h"
#include "Mouse.h"
#include "RandomNumberGenerator.h"
#include "MovableGridItem.h"

using namespace std;

class Nut : public MovableGridItem {

     public:
		 Nut();
		 void spot_mouse(Mouse* p_mouse);
		 char get_symbol();
		 bool has_been_collected();
		 void disappear();
		 void respawn_nut();

		 

     private:
		 bool collected;
		 Mouse* pointer_mouse;
		 RandomNumberGenerator rng;

};