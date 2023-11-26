#include "../includes/map.h"
#include "../includes/game.h" 
#include "../includes/messages.h"

char *get_tiles(char *tiles_file)
{
	char *tiles;
	int fd;
	tiles = (char *)malloc(sizeof(char) * NUM_TILES + 1);
	if (!tiles)
	{
		perror("Allocating Memory for Tiles");
		exit(EXIT_FAILURE);
	}
	print_same_line(":: Opening Tiles", 50000, 2);
	fd = open(tiles_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	print_same_line(":: Reading Tiles", 50000, 2);
	
	if (read(fd, tiles, NUM_TILES) == 0)
	{
		perror("no tiles");
		exit(EXIT_FAILURE);
	}
	tiles[NUM_TILES] = '\0';
	printf(":: Files tiles: %s\n", tiles);
	return (tiles);
}
/**
 * Retrives the ASCII char of the tile required
 * @param: tile (int) the number of the corresponding tile required (1 = veiled, 2 = home, 3 = player, 4 = death, 5 = empty, 6 = tresaure
 */
/*
char get_tile(int tile)
{
	switch (tile)
	{
		case 1:

			close(fd);
			return ();
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
	}

}*/
