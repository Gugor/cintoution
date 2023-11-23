#include "../includes/game.h"
#include "../includes/input.h"
#include "../includes/map.h"
#include "../includes/effects.h"
#include "../includes/messages.h"
#include "../includes/game-console.h"

int GAME_STATUS = 1;  
int G_MAP_SIZE = 10;

int main (int argc, char **argsv)
{
	char input[MAX_INPUT];
//	t_map map;

	if(argc < 1)
		exit(0);
	if(!argsv[0])
		exit(0);
	// Starting game:
	start_game();
	/**
	 * Game Loop
	 * */
	while(GAME_STATUS != 0)
	{
		scanf("%s", input);
		if(GAME_STATUS == 1 && input[0] == 'y')
		{
			sleep(1);
			remove_line();
			print_same_line(":: Creating custom level map...", -1);
		}
		else if(GAME_STATUS == 1 && input[0] == 'n')
		{
			remove_line();
			// Filling the map with base tile
			if (fill_map("assets/veiled-map", G_MAP_SIZE) < 0) 
				return (-1);
			sleep(1);
			// Printing the current state of map
			showcursor(0);
			if (load_map("assets/veiled-map") < 0)
				return (-1);
			showcursor(1);
		}
	}
	return (0);
}
