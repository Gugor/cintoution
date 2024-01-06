
#include "../includes/game.h"
#include "../includes/map.h"
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
 *
int set_difficulty(t_map map, t_difficulty *difficulty)
{
	if (difficulty->level % difficulty->mgrowth->mod == 0)
		difficulty->mgrowth->cangrow = 1;
	else
		difficulty->mgrowth->cangrow = 0;
	difficulty->density->current = difficulty->density->mod; 

}
*/

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
		difficulty->density = &density;
}
