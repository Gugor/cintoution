#include "../includes/input.h"
#include "../includes/game.h"
void clear_terminal() {
    printf("\033[2J\033[H");  // Secuencias de escape ANSI para borrar la pantalla y colocar el cursor en la posición 1,1
}
