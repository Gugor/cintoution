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
int fill_map(char *mappath, int xsize, int ysize)
{
	int mapsize;
	int pos;
	wchar_t base_tile;
	size_t length;
	int fd;
	
	setlocale(LC_ALL, ""); 	//Set the local for the unicode encoding 
    mapsize = xsize * ysize;
    pos = 0;
	base_tile = L'❇';
	length = wcrtomb(NULL, base_tile, 0); 
	fd = open(mappath, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	
	printf("::Preparing for filling map\n");
    if (fd == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }
	printf(" ::Filling map\n");
     while(pos < mapsize)
	 {
		if (pos != 0 && pos % xsize == 0)
		{
			if (write(fd, "\n", 1) == -1)
			{
				perror("An error occurred while writing the map");
				close(fd); 
				return (-1);
			}
		}
        if (write(fd, &base_tile, length * sizeof(wchar_t)) == -1)
		{
			perror("An error occurred while writing the map");
			close(fd); 
			return (-1);
		}
		pos++;
	 }
	printf(" ::Map filled with base tiles\n");
     while(pos < mapsize)
	 if (close(fd) == -1)
	 {
		 perror("An error occurred while closing the file");
		 return (1);
	 }
	printf(" ::Map File Closed\n");
	return (0);
} 

/**
 * Print a map in the terminal
 * @params: map (wchar_t *) the map data to be printed in the console
 */
int load_map(char *mappath)
{
	char buffer[G_MAP_ROWS * G_MAP_COLS + G_MAP_ROWS];
	wchar_t currentmap[G_MAP_ROWS * G_MAP_COLS + G_MAP_ROWS];
	ssize_t bytes_read;
	int fd;

	printf(" ::Preparing locals for printing unicode map\n");
	setlocale(LC_ALL, "");
	fd = open(mappath, O_RDONLY);
    if (fd == -1) {
        perror("open file");
        return (-1);
    }
	bytes_read = 1;
	while ((bytes_read = read(fd, buffer, G_MAP_ROWS * G_MAP_COLS + G_MAP_ROWS)) > 0)
    {
		printf("(%lu)", bytes_read);
		mbstowcs(currentmap, buffer, bytes_read);
		if (print_map(currentmap) < 0)
			return (-1);
	}

	if (close(fd) == -1) {
        perror("close file");
        return (-1);
    }
	return(0);
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
	}
	return(0);
}
