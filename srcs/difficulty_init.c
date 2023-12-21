#include "../includes/game.h"
#include "../includes/map.h"
#include "../includes/messages.h"

/**
 * Density Init
 * This value corresponds on how crowded with dangers a map can be
 */
void  densitiy_init(t_density *density)
{
	density->min		= 0.25;	// The min percentage density can be in a map
	desnsity->max		= 0.6;  // The max percentage density can be in a map
	density->current = min;  // The current density to populate a map with dangers
	density->mod		= 0.1;  // Density multiplier in each growth
}

/**
 *
 */
void map_growth_init(t_mgroth *mg)
{
	mg->cangrow = 0;
	mg->mod = 0.1;
}

/**
 * Difficulty Init
 */
void difficulty_init(t_difficulty *difficulty)
{
	t_density density;
	t_mgrowth map_grth;

	difficulty->level	= 1;
	difficulty->mod		= 0.5;
	density_init(density); 
	map_growth_init(map_grth) 
	dist_to_exit_modifier = 2.0;
}
