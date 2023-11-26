#include "../includes/game.h"
#include "../includes/map.h"
#include "../includes/difficulty.h"
#include "../includes/random.h"


/**
 * Set the player in the map
 *  //TODO
 */
/*
t_player player_init()
{

}*/
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
 * Set the exit in the map
 * //TODO
 *
 */

int exit_init(t_map *map)
{
   if (!map)
   {
		perror("Missing map data. Exit could not be placed in map");
		exit(EXIT_FAILURE);
   }
   
   int mapsize;

   mapsize = map->size * map->size;
   map->exit = randomize(0, mapsize - 1);
   return (1);
}


/**
 * Set the dangerous araeas in the map
 * // TODO
 *
 */
/*
int death_init(t_map map, t_difficulty difficulty)
{
	//CALCULATE DEATHS POINTS DENSITY
	//Spread DEATH POINTS 
	//Check how many path there are to the exit
	//Check if it's accordingly with the difficulty level
	//ok || or repit the process untill maches requirements
}
*/

