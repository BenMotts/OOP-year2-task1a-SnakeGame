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
   mouse.scamper(key);
   snake.chase_mouse();
   apply_rules();
}

vector<vector<char>> Game::prepare_grid()
{
   // create the 2D grid
   vector<vector<char>> grid;

   // for each row
   for (int row = 1; row <= SIZE; ++row)
   {
      // create a row to add to the 2D grid
      vector<char> line;

      // for each column
      for (int col = 1; col <= SIZE; ++col)
      {
         // is the snake at this position?
         if (row == snake.get_y() && col == snake.get_x())
         {
            line.push_back(snake.get_symbol());
			if (snake.returnCounter() > 0)
			{
				line.push_back(snake.bigSnakeBody.at(0).bodyPart1);
				line.push_back(snake.bigSnakeBody.at(0).bodyPart2);
				line.push_back(snake.bigSnakeBody.at(0).bodyPart3);
			}
         }
         // is the mouse at this position?
         else if (row == mouse.get_y() && col == mouse.get_x())
         {
            line.push_back(mouse.get_symbol());
         }
         else
         {
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

		 if (row == 10)
		 {
			 if (col == 5)
			 {
				 line.push_back(nut.get_symbol());
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
   }
   else
	  
   {
	   if (nut.has_been_collected() == true)
	   {
		   if (mouse.has_reached_a_hole(underground))
		   {
			   mouse.escape_into_hole();
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