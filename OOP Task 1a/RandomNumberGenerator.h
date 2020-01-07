#pragma once

#include <stdlib.h>	// for srand and rand
#include <cassert>	// for assert
#include <ctime>	   // for time used in seed

using namespace std;

static class RandomNumberGenerator
{
	public:
		// constructors
		RandomNumberGenerator();

		// accessors
		int get_random_value(const int&) const;

	private:
		// supporting functions
		void seed();
};