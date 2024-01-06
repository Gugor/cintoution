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
//#include "../includes/difficulty.h"

int save_terrain_map(t_map *map)
{
	int pos;
	int fd;
	int maxsize;

	fd = open(TERRAIN_MAP_PATH, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open map");
        return 1;
    }
	pos = -1;
	maxsize = pow(map->size, 2);
    while(++pos < maxsize)
	{
		if ((pos % map->size) == 0)
			write(fd, "\n", 1);
		if (map->terrain[pos])
			write(fd, &map->terrain[pos], 1);
	}
	if (close(fd) == -1)
	{
		perror("close file");
		return (1);
	}
	return (1);

}
/**
 * Fill the terrain with the base tile
 * 
 */
void fill_base_terrain(t_map *map)
{
	int size;

	size = pow(map->size, 2);
	while (--size >= 0)
		map->terrain[size] = map->imgs->base;
}

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
		perror("[map.c] Missing Difficulty Data");
		exit(EXIT_FAILURE);
	}
	// Prepare memory for tarrain
	map->terrain = (char *)calloc(map->size * map->size, sizeof(char) + 1);
	if (!map->terrain)
	{
		perror("No enought space to create the map");
		exit(EXIT_FAILURE);
	}
	map->terrain[(int)pow(map->size, 2) + 1] = '\0';
	fill_base_terrain(map); 
	// Set the exit in the terrain
	print_same_line(":: Init exit tile", 70000, 1);
	set_exit_in(map);
	// Set the player in the terrain
	print_same_line(":: Init player tile", 70000, 1);
	set_player_in(map, difficulty);
	
	// Initialize game data
	print_same_line(":: Init death tiles", 70000, 1);
	set_dangers_in(map, difficulty);
	// Save terrain in file
	print_same_line(":: Preparing to save terrain tiles", 70000, 1);
	save_terrain_map(map);
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
