#include "../includes/game.h"
#include "../includes/map.h"
#include "../includes/difficulty.h"
#include "../includes/random.h"
#include "../includes/mymath.h"
#include "../includes/messages.h"


   // Is ther any requirments/conditions to set the exit?
   		// Can be in a corner?
		// Can be in a side?
		// Should be in the center?
		// ___O__________________
		// |&&&&&&&&&&&&&&&&&&&&|
		// |&                  &|
		// |&         O        &|
		// |&                  &|
		// |&                  &|
		// |&                  &|
		// |&                  &|
		// 0&&&&&&&&&&&&&&&&&&&&|
		// _____________________0


/**
 * Set the player in the map
 *  // TODO
 *  // Calculate distance of the exit:
 *  // The player should be a n distance from the exit
 *  // The distance should be a % of the size of the map
 *  // min distance 15% in the begining?? and then up?
 *  
 */

int player_init(t_map *map, t_difficulty *difficulty)
{	
	t_icoords player_coords;
	int tmp_pos;
	double min_distance;  // A modifier to set Min distance from Player to Exit
	int distance;

	print_message(":: Init player\n", 70000, 2);
	// Testing value we need to init in difficulty init and then in update difficulty
	difficulty->dist_to_exit_modifier = 0.25f;
	// Creates a random seed to use rand function
	initialize_randseed();

	min_distance 	= map->size * difficulty->dist_to_exit_modifier; 
 	// We force the first iteration assigning map size as the initial value 
	distance 		= map->size; 
	tmp_pos 		= randomize(0,pow(map->size,2) - 1);
	player_coords	= index_to_map_coords(map->size, tmp_pos);
	distance 		= idistance(player_coords, index_to_map_coords(map->size, map->exit));

	int rols;

	rols = 0;
	print_message(":: Roling player pos\n", 70000, 2);
	while (distance <= (int)min_distance && rols < 100)
	{
		tmp_pos 		= randomize(0, pow(map->size, 2) - 1);
		player_coords	= index_to_map_coords(map->size, tmp_pos);
		distance = idistance(player_coords, index_to_map_coords(map->size, map->exit));	
		rols++;
	} 
	map->player = tmp_pos;
	return (rols);
}

/**
 * Set the exit in the map
 * 
 *
 */

int exit_init(t_map *map)
{
   if (!map)
   {
		perror("[map-generation.c] Missing map data. Exit could not be placed in map");
		exit(EXIT_FAILURE);
   }
   
   int mapsize;

   mapsize = map->size * map->size;
   map->exit = randomize(0, mapsize - 1);
   return (1);
}


/**
 * Scatter death point on map terrain
 *
 */
static void scatter_death_points(t_map *map)
{
	int pos;
	int death_points;
	int iterations;

	iterations = 0;
	printf("Selecting dangers\n");
	death_points = map->dangers;
	printf("Init dangers\n");
	while (death_points > 0 || iterations < 1000) 
	{
		pos = randomize(0, map->size * map->size - 1); 
		printf(":: Rand pos %d", pos);
		//check_point_exist(pos);					// CHECK POS EXISTS //TODO	
												
		if (!map->terrain[pos])
		{
			printf("Setting death point[%d] [%d/%d]", pos, map->dangers - death_points, map->dangers);
			map->terrain[pos] = map->imgs->danger;
			death_points--;
		}
		++iterations;
	}
	printf("%s\n", map->terrain);
}

/**
 * Set the dangerous araeas in the map
 * // TODO
 *
 */
void death_init(t_map *map, t_difficulty *difficulty)
{
	//CALCULATE DEATHS POINTS DENSITY
	//Spread DEATH POINTS 
	//Check how many path there are to the exit
	//Check if it's accordingly with the difficulty level
	//ok || or repeat the process untill maches requirements
	initialize_randseed();
	map->dangers = 0;
	map->dangers = pow(map->size,2) * difficulty->density->current;
	scatter_death_points(map);
}


