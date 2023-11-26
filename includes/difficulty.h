
#ifndef DIFFICULTY_H
# define DIFFICULTY_H


typedef struct s_density
{
	int density;	// density  
	int density_min;
	int density_max;
	int density_mod;
} t_density;

typedef struct s_mgrowth
{
	int grow_map;	// 0 || 1 
	int growth_mod;	
} t_mgrowth;

typedef struct s_difficulty
{
	int level;
	t_density *density;
	t_mgrowth *mgrowth;
} t_difficulty;

#endif
