#ifndef GAME_H
# define GAME_H
// Macros

// Dependencies
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
// Globals
extern int GAME_STATUS; // 0 = ExitGame; 1 = GameRunning; 2 = GameOver
// Game Functions Prototypes
void start_game();
#endif
