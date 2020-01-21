#pragma once

#include "Constants.h"
#include "Underground.h"
#include "RandomNumberGenerator.h"
#include "MovableGridItem.h"

class Mouse : public MovableGridItem
{
	public:
		// constructor
		Mouse();

		// accessors

		bool is_alive() const;
		bool has_escaped() const;
		bool has_reached_a_hole(Underground ug);


		// mutators
		void die();
		void escape_into_hole();
		void scamper(const int& key);
		void respawn_mouse();
		void initialise_position();
		void teleport_holes(const int& x, const int& y);

	private:
		// data members
		bool alive;
		bool escaped;
		int mouse_dx;
		int mouse_dy;
		RandomNumberGenerator rng;

		// supporting functions 

		void update_position(const int& dx, const int& dy);
};