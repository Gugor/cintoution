#ifndef MAP_H
# define MAP_H
// Dependencies
#include <fcntl.h>
#include <wchar.h>
#include <locale.h>
// Globals
extern int G_MAP_ROWS;
extern int G_MAP_COLS;

// Map Functions prototips
int fill_map(char *mappath, int xsize, int ysize);
int print_map(wchar_t *map);
int load_map(char *mappath);
#endif
