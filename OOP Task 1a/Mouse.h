#pragma once

#include "Constants.h"
#include "Underground.h"
#include "RandomNumberGenerator.h"

class Mouse
{
	public:
		// constructor
		Mouse();

		// accessors
		int get_x() const;
		int get_y() const;
		char get_symbol() const;
		bool is_at_position(const int& x, const int& y);
		bool is_alive() const;
		bool has_escaped() const;
		bool has_reached_a_hole(Underground ug);


		// mutators
		void die();
		void escape_into_hole();
		void scamper(const int& key);
		void respawn_mouse();
		void initialise_position();

	private:
		// data members
		bool alive;
		bool escaped;
		int mouse_dx;
		int mouse_dy;
		int x, y;
		char symbol;
		RandomNumberGenerator rng;

		// supporting functions 

		void update_position(const int& dx, const int& dy);
};