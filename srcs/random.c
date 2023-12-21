#include "../includes/random.h"
#include "../includes/game.h"
/**
 * Creates a random number between a min and a max value
 * @param min (int) min number of the range
 * @param max (int) max number of the range
 */
int randomize(int min, int max)
{
	return (min + rand() % (max - min + 1));
}
void initialize_randseed()
{
	srand(time(NULL));
}
