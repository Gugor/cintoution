#include "../includes/game-console.h"
#include "../includes/game.h"

/**
 * Toggles the cursor in the game console
 * @param: show (int) 0 = hides cursor, 1 = shows cursor
 */
int showcursor(int show)
{
	if (show)
	{
		printf("\e[?25h");
		fflush(stdout);
		return(0);
	}
	else
	{
		printf("\e[?25l");
		fflush(stdout);
		return (1);
	}
}

/**
 * Remove the last printed line 
 */
int remove_line()
{
	if (write(1, "\r\033[k", 5) < 0)
	{
		perror("removing line");
		return (-1);
	}
	else
		return (0);
}
