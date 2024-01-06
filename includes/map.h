#ifndef MAP_H
# define MAP_H
// Dependencies
# include <fcntl.h>
# include <wchar.h>
# include <locale.h>
# include <unistd.h>
# include <math.h>
# include "difficulty.h"
// Macros
# ifndef NUM_TILES
#  define NUM_TILES 7 
# endif

# ifndef CURRENT_MAP_PATH
#  define CURRENT_MAP_PATH "assets/veiled-map.txt"
# endif

# ifndef TERRAIN_MAP_PATH
#  define TERRAIN_MAP_PATH "assets/terrain-map.txt"
# endif

# ifndef TILES_FILE
#  define TILES_FILE "assets/tiles.txt" 
# endif

# ifndef TILES_INDX_PLAYER
#  define TILES_INDX_PLAYER 2 
# endif

# ifndef TILES_INDX_DEATH
#  define TILES_INDX_DEATH 0 
# endif

# ifndef TILES_INDX_EXIT
#  define TILES_INDX_EXIT 1 
# endif

# ifndef TILES_INDX_DANGER
#  define TILES_INDX_DANGER 3 
# endif

# ifndef TILES_INDX_FOG
#  define TILES_INDX_FOG 4 
# endif

# ifndef TILES_INDX_BASE
#  define TILES_INDX_BASE 5 
# endif

# ifndef TILES_INDX_VERIFY
#  define TILES_INDX_VERIFY 6 
# endif

#include "difficulty.h"
// ... Globals  ... //
extern int G_MAP_SIZE;

// ... Structs ... //
typedef struct s_tile_imgs
{	
	char	player;
	char	exit;
	char	death;
	char	danger;
	char	fog;
	char	base;
	char	verify;
} t_tile_imgs;

typedef struct s_map
{	
	int			size;
	char		*current_path;
	char		*terrain_path;
	t_tile_imgs	*imgs;
	int			player;
	int			exit; 
	int			dangers;    //The number of tiles in terrain that can kill the player
	char		*terrain;
	char		*current;
} t_map;

typedef struct s_density
{
	double current;
	double min;  //Min value % of density
	double max;  //Max value % of density
	double mod;  //Modifier of density in each level
} t_density;

typedef struct s_mgrowth
{
	int cangrow;    // 0 || 1
	double mod;
} t_mgrowth;

typedef struct s_difficulty
 {
     int level;
     double mod;
     t_density *density;
     t_mgrowth *mgrowth;
     double dist_to_exit_modifier; // Min distance beteewn player and exit to  set player position
 } t_difficulty;

// ***** PROTOTYPES ****** //
//			... Map ... //
int			hide_map(char *mappath, int size, char fog);
int			create_terrain(t_map *map, t_difficulty *difficulty);
int			print_map(char **map);
int			load_map(char *mappath);
//int update_map(t_map *map); // TODO
//			... Map Init ... //
t_map		*map_init();
t_tile_imgs	*map_images_init();
//			... Map Utilities ... //
char		*get_tiles(char *tiles_file);
//			... Map Generator ... //
int			set_exit_in(t_map *map);
int			set_player_in(t_map *map, t_difficulty *difficulty);
void		set_dangers_in(t_map  *map, t_difficulty *difficulty);
//			... Difficulty ... //
void		difficulty_init(t_difficulty *difficulty);
void		density_init(t_difficulty *difficulty);
#endif
