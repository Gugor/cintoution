#ifndef DIFFICULTY_H
# define DIFFICULTY_H
// Dependencies
# include "map.h"
// Macros

# ifndef MIN_DENSITY
#  define MIN_DENSITY 0.1f
# endif

# ifndef MAX_DENSITY
#  define MAX_DENSITY 0.55f
# endif

# ifndef MOD_DENSITY
#  define MOD_DENSITY 1.05f
# endif

# ifndef MOD_MGROTH
#  define MOD_MGROWTH 1.1f
# endif
// Structs
struct s_map;
typedef struct s_density
{
	double current;	  
	double min;  //Min value % of density
	double max;  //Max value % of density
	double mod;  //Modifier of density in each level
} t_density;

typedef struct s_mgrowth
{
	int cangrow;	// 0 || 1 
	int mod;	
} t_mgrowth;

typedef struct s_difficulty
{
	int level;
	double mod;
	t_density *density;
	t_mgrowth *mgrowth;
	double dist_to_exit_modifier; // Min distance beteewn player and exit to set player position
} t_difficulty;

// PROTOTYPES
//int difficulty_init(t_map *map, t_difficulty *difficulty);
//t_density density_init(t_map map);

#endif
