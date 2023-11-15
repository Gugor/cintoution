#ifndef MAP_H
# define MAP_H
// Dependencies
#include <wchar.h>
#include <locale.h>
// Globals
extern int G_MAP_ROWS;
extern int G_MAP_COLS;

// Map Functions prototipes
int fill_map(wchar_t **map_data, int xsize, int ysize);
int print_map(wchar_t *map);
#endif
