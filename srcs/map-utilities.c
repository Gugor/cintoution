# include "include/map.h"


char *get_tiles(char *tiles_file)
{
	char tiles[NUM_TILES];
	int fd;

	fd = open(TILES_FILE, O_RONLY);
	
	if (read(fd, tiles, NUM_TILES) == 0)
	{
		perror("no tiles");
		return (-1);
	}
}
/**
 * Retrives the ASCII char of the tile required
 * @param: tile (int) the number of the corresponding tile required (1 = veiled, 2 = home, 3 = player, 4 = death, 5 = empty, 6 = tresaure
 */
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

}
