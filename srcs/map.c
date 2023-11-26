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
#include "../includes/messages.h"
#include "../includes/random.h"
#include "../includes/difficulty.h"

/**
 * Create a map with an exit, dangers and the player
 * according with the level of difficulty
 *
 */
int create_terrain(t_map *map, t_difficulty *difficulty)
{
	if (!map)
	{
		perror("Missing data Map Data");
		exit(EXIT_FAILURE);
	}

	if (!difficulty)
	{
		// Set random exit
		exit_init(map);

	}
	/*
	{
		perror("Missing Difficulty Data");
		exit(EXIT_FAILURE);
	}*/

	//int fd;
	// * * * * *
	// * * * * *   // 7 % 5 = 2 cols 		-> 7 / 5 = 1 + 1 = 2 rows
	// * * * * *   // 8 % 5 = 3 cols 		-> 8 / 5 = 1 + 1 = 2 rows
	// * * * * *   // 15 % 5 = 0 = 5 cols 	-> 12 / 5 = 2 + 1 = 3 rows
	// * * * * *
	printf(":: Exit set at pos %d (x=%d,y=%d)\n", map->exit , (map->exit % map->size) == 0 ? map->size - 1 : (map->exit % map->size) - 1 , (map->exit / map->size));
	//fd = open(map->);
	return (1);
}


/**
 *  Fill the map with veiled tiles
 *  @param: map_data (wchar_t **) the map to be filled
 *  @param: xsize (int) the number of columns of the map
 *  @param: ysize (int) the number of rows of the map
 */
int hide_map(char *mappath, int size, char fog)
{
	int mapsize;
	int pos;
	int fd;
	
    mapsize = size * size;
    pos = 0;

	print_message(":: Open map file: \n", 10000, 2);
	sleep(1);
	fd = open(mappath, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open map");
        return 1;
    }
    while(pos < mapsize)
	{
		if (pos != 0 && pos % size == 0)
		{
			if (write(fd, "\n", 1) == -1)
			{
				perror("writing map");
				close(fd); 
				return (-1);
			}
		}
        if (write(fd, &fog, 1) == -1)
		{
			perror("writing map");
			close(fd); 
			return (-1);
		}
		pos++;
	}
	if (close(fd) == -1)
	{
		perror("close file");
		return (1);
	}
	return (1);
} 

/**
 * Print a map in the terminal
 * @params: map (wchar_t *) the map data to be printed in the console
 */
int load_map(char *mappath)
{
	char *currentmap;
	ssize_t bytes_read;
	int fd;

	currentmap = (char *)calloc(G_MAP_SIZE * G_MAP_SIZE + G_MAP_SIZE, sizeof(char *));
	if (!currentmap)
	{
		perror("Map could not be loaded");
		exit(EXIT_FAILURE);
	}
	if ((fd = open(mappath, O_RDONLY)) < 0) 
	{
        perror("open file");
        return (-1);
    }
	bytes_read = 1;
	if ((bytes_read = read(fd, currentmap, G_MAP_SIZE * G_MAP_SIZE + G_MAP_SIZE)) > 0)
    {
		if (write(1, "\n\n", 2) < 0)
		{
			perror("write map");
			return (-1);
		}
		if (print_map(&currentmap) < 0)
			return (-1);
		if (write(1, "\n\n", 2) < 0)
		{
			perror("write map");
			return (-1);
		}
		
	}
	else
	{
		perror("map empty");
		return (-1);
	}

	if (close(fd) == -1)
	{
        perror("close file");
        return (-1);
    }
	return(1);
}

/**
 * Print a map in the terminal
 * @params: map (wchar_t *) the map data to be printed in the console
 */
int print_map(char **map)
{
	int pos;
	char *m;

	pos = 0;
	m = *map;

	print_message_with_separator(m, -1, 10000, ' ');

	if(map || *map)
	{
		free(*map);
		map = NULL;
	}
	return(pos);
}
/**
 * Update map with new player position
 *
 */
/*
int update_map(t_map map)
{

}
*/
