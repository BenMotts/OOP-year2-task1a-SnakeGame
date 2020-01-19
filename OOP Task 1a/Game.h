#pragma once

#include <string>		
#include <assert.h>	
#include <vector>

#include "Mouse.h"
#include "Snake.h"
#include "Underground.h"
#include "Nut.h"
#include "Player.h"

using namespace std;

class Game
{
private:
	Mouse mouse;
	Snake snake;
	Underground underground;
	Nut nut;
	Player player1;
public:
	//Constructor
	void set_up();
	void process_input(const int& key);
	vector<vector<char>> prepare_grid();
	void apply_rules();
	bool is_running();
	int find_hole_number_at_position(const int& x, const int& y);
	string get_end_reason();
	void restart_game();
	Player* getPlayerPtr();

};