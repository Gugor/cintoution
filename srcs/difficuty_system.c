
#include "../include/game.h"
#include "../include/difficulty.h"
/**
 * The map difficulty can change respecting 3 variables: map size, density(number of mortal tiles/tiles)
 * count down time (need to confirm this)
 *
 *
 *
 */
int set_difficulty(t_map map, t_difficulty *difficulty)
{
	if (difficulty.level % difficulty.growth_modfier)
		difficulty.grow_map = 1;
	else
		difficulty.grow_map = 0;
	difficulty.density = difficulty.density_mod 

}
