
#include "../include/game.h"
#include "../include/map.h"

#ifndef MAP_PATH
# define MAP_PATH "assets/veiled-map"
#endif

 t_map *map-init(t_map map)
 {
     map.rows		= G_MAP_SIZE;
	 map->path		= MAP_PATH;
	 // map->imgs	= tiles__init();    // TODO
	 // map.pos		= get_player_pos(); // TODO
     // map.terrain = create_terrain(); // TODO
	 map->current	= fill_map(map->path, map.size);
 }

