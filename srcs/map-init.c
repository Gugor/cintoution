
#include "../includes/game.h"
#include "../includes/map.h"
#include "../includes/messages.h"
#include "../includes/random.h"
/**
 * Init map. Create a map struct in memory with initial values
 *
 */
t_map *map_init()
{
	t_map *map;
	t_difficulty difficulty;
	print_same_line(":: Alocating MAP Memory",70000, 1);
	initialize_randseed();
	map = (t_map *)malloc(sizeof(t_map));
	if(!map)
		return (0); 
	map->size			= G_MAP_SIZE;
	map->current_path	= CURRENT_MAP_PATH;
	map->terrain_path	= TERRAIN_MAP_PATH;
	print_same_line(":: Initializing map images",70000, 1);
	map->imgs			= map_images_init();   
	print_same_line(":: Creating Terrain", 70000, 1);
	difficulty_init(&difficulty);
	create_terrain(map, &difficulty); // TODO
	if (map->imgs)
		hide_map(map->current_path, map->size, map->imgs->fog); // Change func name to hide_map(); //TODO
	// map->current	= get_current_map(); // TODO
	return (map);
 }

t_tile_imgs *map_images_init()
{
	t_tile_imgs *imgs;
	char *tiles;

	imgs = (t_tile_imgs *)malloc(sizeof(t_tile_imgs));
	if (!imgs)
		exit(EXIT_FAILURE);
	print_same_line(":: Fetching Tiles File",70000,1);
	tiles = get_tiles(TILES_FILE);
	if(!tiles)
	{
		perror("Error retrieving tiles");
		exit(EXIT_FAILURE);
	}
	imgs->player	= tiles[TILES_INDX_PLAYER];
	imgs->exit		= tiles[TILES_INDX_EXIT];
	imgs->death		= tiles[TILES_INDX_DEATH];
	imgs->danger	= tiles[TILES_INDX_DANGER];
	imgs->fog		= tiles[TILES_INDX_FOG];
	imgs->base		= tiles[TILES_INDX_BASE];
	imgs->verify	= tiles[TILES_INDX_VERIFY];
	return (imgs);
}

