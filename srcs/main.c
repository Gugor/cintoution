#include "../includes/game.h"
#include "../includes/input.h"
#include "../includes/map.h"
#include "../includes/effects.h"

int GAME_STATUS = 1;  
int G_MAP_ROWS = 6;
int G_MAP_COLS = 10;

int main (int argc, char **argsv)
{
	char input[MAX_INPUT];

	if(argc < 1)
		exit(0);
	if(!argsv[0])
		exit(0);
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
			printf(":: Creating custom level map...\n\n");
		}
		else if(GAME_STATUS == 1 && input[0] == 'n')
		{
			sleep(1);
			printf(":: MAP(%ix%i) tiles:\n",G_MAP_ROWS, G_MAP_COLS);
			// Filling the map with base tile
			if (fill_map("assets/veiled-map", G_MAP_COLS, G_MAP_ROWS) < 0) 
				return (-1);
			printf("Preparing for printig map\n");
			// Printing the current state of map
			if (load_map("assets/veiled-map") < 0)
				return (-1);
		}
	}
	return (0);
}
