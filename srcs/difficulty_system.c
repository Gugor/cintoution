
#include "../include/game.h"
#include "../include/difficulty.h"
/**
 * The map difficulty can change respecting 3 variables: map size, density(number of mortal tiles/tiles)
 * count down time (need to confirm this)
 *
 *
 *
 */

/**
 * 
 *
 */
int set_difficulty(t_map map, t_difficulty *difficulty)
{
	if (difficulty->level % difficulty->growth_modfier)
		difficulty->grow_map = 1;
	else
		difficulty.grow_map = 0;
	difficulty->density.current = difficulty->density_mod 

}

/**
 * Difficulty Initialization we set the default values;
 *
 *
 */
int difficulty_init(t_map *map, t_difficulty *difficulty)
{
	t_density density;
	//t_mgrowth mgrowth;
	
	density = density_init(map, difficulty);
	//mgrowth = mgrowth_init(map, difficulty); //TODO
}

/**
 *  We initialize density to the initial values
 *  
 *
 */
void density_init(t_difficulty *difficulty)
{
		t_density density;

		density.min = MIN_DENSITY; // The min percentage density can be in a map
		density.max = MAX_DENSITY; // The max percentage density can be in a map
		density.mod = MOD_DENSITY; // The current density to populate a map with    dangers
		density.current = density.min * difficulty->mod; // Density multiplier in each growth
		difficulty->density = density;
}

/**
 * The ratio of growth of the map
 *
 *
 */
/**
  *
  */
void map_growth_init(t_mgroth *mg)
{
	mg->cangrow = 0;
	mg->mod = 0.1;
}
