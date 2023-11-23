#ifndef MAP_H
# define MAP_H
# ifndef NUM_TILES
#  define NUM_TILES 6
# endif
# ifndef TILES_FILE
#  define TILES_FILE "asset/tiles"
# endif
// Dependencies
#include <fcntl.h>
#include <wchar.h>
#include <locale.h>
// Globals
extern int G_MAP_SIZE;

//Structs
typedef struct s_tile_imgs
{	
	char *player;
	char *exit;
	char *death;
	char *danger;
	char *fog;
} t_tile_imgs;

typedef struct s_map
{	
	int size;
	char *path;
	t_tile_imgs *imgs;
	char *pos;
	char *terrain;
	char *current;
} t_map;


// Map Functions prototips
int fill_map(char *mappath, int size);
int print_map(char **map);
int load_map(char *mappath);
t_map *map_init(t_map map);

#endif
