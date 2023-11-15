#include "../includes/game.h"
#include "../includes/input.h"
#include "../includes/effects.h"
void start_game()
{
	clear_terminal();
	printf("\n");
	printf("            ::::::::::::::::::::::::\n");
	printf("            :: \033[5;94mINTUITION THE GAME\033[0m ::\n");
	printf("            ::::::::::::::::::::::::\n\n");
	sleep(1);
	printf("..................................................\n");
	printf("::       Press %s\'ctrl + c\'%s to exit the game      ::\n", CLR_B_BLUE, CLR_E_RESET);
	printf("..................................................\n");
	printf("\n");
	printf("=> Would you like to set a custom level? (y/n): ");	
}
