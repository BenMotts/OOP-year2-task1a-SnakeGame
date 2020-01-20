#include "Game.h"




void Game::set_up()
{
	// set up the holes
	underground.set_hole_no_at_position(0, 4, 3);
	underground.set_hole_no_at_position(1, 15, 10);
	underground.set_hole_no_at_position(2, 7, 15);

	// mouse state already set up in its contructor

	// set up snake
	snake.position_at_random();
	snake.spot_mouse(&mouse);
	nut.spot_mouse(&mouse);
}

void Game::process_input(const int& key)
{
	if (key == CHEAT_MODE && cheatMode)
		cheatMode = false;
	else if (key == CHEAT_MODE && !cheatMode) {
		cheatMode = true;
		hasCheated = true;
	}
	else
		mouse.scamper(key);
	if (!cheatMode)
		snake.chase_mouse();
	apply_rules();
}

vector<vector<char>> Game::prepare_grid()
{
	// create the 2D grid
	vector<vector<char>> grid;
	bool snakePos;
	// for each row
	for (int row = 1; row <= SIZE; ++row)
	{
		snakePos = false;
		// create a row to add to the 2D grid
		vector<char> line;
		// for each column
		for (int col = 1; col <= SIZE; ++col)
		{
			snakePos = false;
			// is the snake at this position?
			for (int i(0); i < snake.snakeBody.size(); ++i) {
				if (row == snake.snakeBody.at(i).get_y() && col == snake.snakeBody.at(i).get_x()) {
					line.push_back(snake.snakeBody.at(i).get_symbol());
					snakePos = true;
				}
			}
			// is the mouse at this position?
			if (row == mouse.get_y() && col == mouse.get_x() && !snakePos)
			{
				line.push_back(mouse.get_symbol());
			}
			else if (nut.is_at_position(col, row) && !snakePos) {
				line.push_back(nut.get_symbol());
			}
			else if (!snakePos) {
				// is there a hole at this position?
				const int hole_no = find_hole_number_at_position(col, row);

				if (hole_no != -1)
				{
					line.push_back(underground.get_hole_symbol(hole_no));
				}
				else
				{
					// none of the above, must be nothing at this position
					line.push_back(FREECELL);
				}
			}


		}

		// now that the row is full, add it to the 2D grid
		grid.push_back(line);
	}

	return grid;
}

int Game::find_hole_number_at_position(const int& x, const int& y)
{
	for (size_t h_no = 0; h_no < underground.get_hole_count(); ++h_no)
	{
		if (underground.is_hole_at_position(h_no, x, y))
		{
			return h_no;
		}
	}

	return -1; // not a hole
}

void Game::apply_rules()
{
	if (snake.has_caught_mouse())
	{
		mouse.die();
		player1.update_score(-1);
	}
	else

	{
		if (nut.has_been_collected() == true)
		{
			if (mouse.has_reached_a_hole(underground))
			{
				mouse.escape_into_hole();
				if (!hasCheated)
					player1.update_score(1);
			}
		}
		if (nut.has_been_collected() == true)
			nut.disappear();


	}
}

bool Game::is_running()
{
	return mouse.is_alive() && !mouse.has_escaped();
}

string Game::get_end_reason()
{
	if (mouse.has_escaped())
		return "You escaped underground!";

	return "The snake ate you!";
}


void Game::restart_game()
{
	hasCheated = false;
	cheatMode = false;
	mouse.respawn_mouse();
	nut.respawn_nut();
	snake.update_counter(0);
}

Player * Game::getPlayerPtr()
{
	return &player1;
}

bool Game::isCheating() const {
	return cheatMode;
}


