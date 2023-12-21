#ifndef MYMATH_H
# define MYMATH_H
// Dependencies
#include <math.h>

//Macros


// Structs

typedef struct s_fcoords 
{
	double x;
	double y;
} t_fcoords;

typedef struct s_coords 
{
	int x;
	int y;
} t_icoords;

//PROTOTYPES
int idistance(t_icoords point1, t_icoords point2);
//double disitance(t_fcoords point1, t_fcoords point2);
t_icoords index_to_map_coords(int size, int mapindex);
void initialize_randseed();
#endif
