#include "../includes/mymath.h"

/**
 * Gets to points in the map and calculate the distnace between them
 *
 * @param: point1 (t_coord) point one in space
 * @param: point2 (t_coord) point two in space
 */
int idistance(t_icoords point1, t_icoords point2)
{
	int x;
	int y;
	//We take to points: p1 = {1,3} y p2 = {4,2}, first part of the matrix is X and 2nd is Y
	//So p1(x,y)
	//To calculate distance we need to substract p2 from p1 to do so we do p1.x - p2.x and p1.y - p2.y
	//Then we square the results: (1 - 4)^2 and (3-2)^2
	// x= 9 and y= 1
	// then saquare the results √(9 + 1) = 3,16
	x = point1.x - point2.x;
	y = point1.y - point2.y;

	return (sqrt(pow((double)x,2) + pow((double)y,2)));
}

/**
 * Calculate the x & y from an index
 *  
 *
 */
t_icoords index_to_map_coords(int size, int mapindex)
{
	t_icoords pos;

	//We are working with arr index so we start at 0 not 1, that's why we rest - 1 to the positions that 
	//starts in 1. 
	//Get x (horizontalor cols) 
	//if the mod of the index and the map size (cols) is 0 means got into the right limit 
	//so limit is size - 1 because we start at 0 for the index arr[0]
	//Otherwise we are inside of the line limits and we just get the 
	//rest - 1 because we are working with index.
	pos.x = (mapindex % size) == 0 ? size - 1 : (mapindex % size) - 1; 
	//Get y (vertical lines) here we consider dividing the index / map->size to get the current row
	//we dont care about the floting point
	pos.y = (mapindex / size);
	return (pos);
}

