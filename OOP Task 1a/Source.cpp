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
			if (game.isCheating()) {
				DrawText("CHEAT MODE ENABLED", 600, 100, 20, YELLOW);
			}
			else 
				DrawText("Press 'C' To Cheat", 600, 100, 20, YELLOW);
			if (game.hasCheated())
				DrawText("No score recorded this turn", 600, 120, 20, GOLD);
			DrawText("Press 'ESC To Quit", 600, 255, 15, RED);

			if (game.is_running())
			{
				string score = to_string(player1->get_score());
				if (IsKeyPressed(KEY_RIGHT))  game.process_input(KEY_RIGHT);
				if (IsKeyPressed(KEY_LEFT))   game.process_input(KEY_LEFT);
				if (IsKeyPressed(KEY_UP))     game.process_input(KEY_UP);
				if (IsKeyPressed(KEY_DOWN))   game.process_input(KEY_DOWN);
				if (IsKeyPressed(CHEAT_MODE)) game.process_input(CHEAT_MODE);
			}
			else
			{
				DrawText("Press 'R' To Restart", 600, 235, 15, SKYBLUE);
				if (IsKeyPressed(RESTART)) {
					game.set_up();
					game.restart_game();
				}
				if (IsKeyPressed(ESCAPE))
					CloseWindow();
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
					case MOUSE:
						if (!game.isCheating())
							DrawRectangle(xPosition, yPosition, cellSize, cellSize, GREEN);
						else
							DrawRectangle(xPosition, yPosition, cellSize, cellSize, YELLOW);
						break;
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


