#include "../includes/game.h"
#include "../includes/map.h"
#include "../includes/messages.h"

/**
 * Density Init
 * This value corresponds on how crowded with dangers a map can be
 */
void density_init(t_difficulty *difficulty)
{
         t_density density;

         density.min = MIN_DENSITY; // The min percentage density can be in a  map
         density.max = MAX_DENSITY; // The max percentage density can be in a  map
         density.mod = MOD_DENSITY; // The current density to populate a map   with    dangers
         density.current = density.min * difficulty->mod; // Density           multiplier in each growth
         difficulty->density = &density;
}

/**
 *
 */
void map_growth_init(t_difficulty *difficulty)
{
	t_mgrowth mg;

	mg.cangrow = 0;
	mg.mod = 0.1;
	difficulty->mgrowth = &mg;
}

/**
 * Difficulty Init
 */
void difficulty_init(t_difficulty *difficulty)
{
	difficulty->level	= 1;
	difficulty->mod		= 0.5;
	density_init(difficulty); 
	map_growth_init(difficulty); 
	difficulty->dist_to_exit_modifier = 2.0;
}
