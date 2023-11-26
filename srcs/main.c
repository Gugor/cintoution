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
	t_map *map;

	if(argc < 1)
		exit(EXIT_FAILURE);
	if(!argsv[0])
		exit(EXIT_FAILURE);
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
			print_same_line(":: Creating custom level map...",0 ,2);
		}
		else if(GAME_STATUS == 1 && input[0] == 'n')
		{
			remove_line();
			map = map_init();
			if(!map)
			{
				perror("Error in map init");
				exit(EXIT_FAILURE);
			}
			// Filling the map with base tile
			
			sleep(1);
			// Printing the current state of map
			showcursor(0);
			if (load_map(map->current_path) < 0)
				return (-1);
			showcursor(1);
		}
	}
	return (0);
}
