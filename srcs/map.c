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

/**
 *  Fill the map with veiled tiles
 *  @param: map_data (wchar_t **) the map to be filled
 *  @param: xsize (int) the number of columns of the map
 *  @param: ysize (int) the number of rows of the map
 */
int fill_map(char *mappath, int size)
{
	int mapsize;
	int pos;
	int fd;
	char base_tile;
	
    mapsize = size * size;
    pos = 0;
	base_tile = 'X';

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
        if (write(fd, &base_tile, 1) == -1)
		{
			perror("writing map");
			close(fd); 
			return (-1);
		}
		pos++;
	}
    while(pos < mapsize)
	{
		if (close(fd) == -1)
		{
			perror("close file");
			return (1);
		}
		pos++;
	}
	return (0);
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
	return(0);
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

	print_message(m, -1, '.');

	if(map || *map)
	{
		free(*map);
		map = NULL;
	}
	return(pos);
}
