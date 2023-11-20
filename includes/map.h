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
extern int G_MAP_ROWS;
extern int G_MAP_COLS;

// Map Functions prototips
int fill_map(char *mappath, int xsize, int ysize);
int print_map(char **map);
int load_map(char *mappath);
#endif
