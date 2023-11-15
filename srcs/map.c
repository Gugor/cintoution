// I need to open the map
// I need to read the map
// I need to print the map
// I need to verify if the map is correct
	// The map needs to fit the size
	// The map needs to have an exit position
	// the map needs to have a player positio
	// All the tiles need to be veilde exeption player
// a map has tiles
	// tile has position, state, type
	// veil type ❇
	// exit 🏠
	// player 🐥🐵🐶🐸🐹🐺🐻
// mapData stores player position, exit position, effects positions
//
#include "../includes/map.h"
#include "../includes/game.h"

/**
 *  Fill the map with veiled tiles
 *  @param: map_data (wchar_t **) the map to be filled
 *  @param: xsize (int) the number of columns of the map
 *  @param: ysize (int) the number of rows of the map
 */
int fill_map(wchar_t **map_data, int xsize, int ysize)
{
	int mapsize;
	int pos;

     if (!map_data)
         return (1);
     mapsize = xsize * ysize;
     pos = 0;
     setlocale(LC_CTYPE, "");
     while(pos < mapsize)
         (*map_data)[pos++] = L'❇';
     (*map_data)[pos++] = '\0';
     if (!(*map_data)[pos++])
         return (1);
     else
         return (0);
} 

/**
 * Print a map in the terminal
 * @params: map (wchar_t *) the map data to be printed in the console
 */
int print_map(wchar_t *map)
{
	int pos;

	pos = 0;
	while (*(map + pos))
    {
		if(wprintf(L"%lc",*(map + pos++)) < 0)
			return (1);
		if (pos != 0 &&  (pos + 1) % G_MAP_COLS == 1)
			printf("\n");
	}
	return(0);
}
