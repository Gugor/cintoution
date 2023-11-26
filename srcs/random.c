#include "../includes/random.h"
#include "../includes/game.h"
/**
 * Creates a random number between a min and a max from a range
 *
 */
int randomize(int min, int max)
{
	if (!max)
		return (0);

	srand(time(NULL));
	return (min + rand() % (max - min + 1));
}
