#include "raylib.h"
#include "Game.h"
#include <iostream>




int main()
{
	bool continueGame1(char x);
	InitWindow(900, 600, "OOP Assignment 1");
	SetTargetFPS(60);

	Game game;
	string playerName;
	Player* player1 = game.getPlayerPtr();
	char input = ' ';


	cout << "Enter your name" << endl;
	cin >> playerName;
	player1->update_name(playerName);
	game.set_up();

		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(DARKGRAY);

			if (player1->get_name() != "")
			{
				DrawText("Player Name: ", 600, 80, 20, RED);
				DrawText(player1->get_name().c_str(), 750, 80, 20, RED);
				DrawText("Press ESC to quit or R to restart game", 600, 235, 15, LIGHTGRAY);
				
				if(game.is_running())
				{
					string score = to_string(player1->get_score());
					if (IsKeyPressed(KEY_RIGHT))  game.process_input(KEY_RIGHT);
					if (IsKeyPressed(KEY_LEFT))   game.process_input(KEY_LEFT);
					if (IsKeyPressed(KEY_UP))     game.process_input(KEY_UP);
					if (IsKeyPressed(KEY_DOWN))   game.process_input(KEY_DOWN);
				}
				else
				{
					cout << "Please press R to restart game"<<endl;
					cin >> input;
					if ((input == 'r') || ((input == 'R')))
					{
						game.set_up();
						game.restart_game();
					}
					
				}


				const int cellSize = (int)((float)GetScreenHeight() / (float)(SIZE));

				const auto grid = game.prepare_grid();

				for (int x = 0; x < SIZE; x++)
				{
					for (int y = 0; y < SIZE; y++)
					{
						int xPosition = x * cellSize;
						int yPosition = y * cellSize;

						switch (grid[y][x])
						{
						case HOLE:       DrawRectangle(xPosition, yPosition, cellSize, cellSize, BLACK);     break;
						case SNAKEHEAD:  DrawRectangle(xPosition, yPosition, cellSize, cellSize, RED);       break;
						case MOUSE:      DrawRectangle(xPosition, yPosition, cellSize, cellSize, GREEN);     break;
						case FREECELL:   DrawRectangle(xPosition, yPosition, cellSize, cellSize, DARKGREEN); break;
						case SNAKEBODY:  DrawRectangle(xPosition, yPosition, cellSize, cellSize, BLUE);      break;
						case NUT:        DrawRectangle(xPosition, yPosition, cellSize, cellSize, DARKPURPLE); break;
						default:         assert(false); // if this assert triggers there's an unrecognised tile on the grid!
						}

						// draw lines around each tile, remove this if you don't like it!
						DrawRectangleLines(x * cellSize, y * cellSize, cellSize, cellSize, DARKGRAY);
					}
				}


			
			}
			string score = to_string(player1->get_score());
			DrawText("Player Score: ", 650, 350, 20, WHITE);
			DrawText(score.c_str(), 820, 350, 20, WHITE);
			EndDrawing();

		}


	CloseWindow();

	return 0;
}


