#ifndef MESSAGES_H
# define MESSAGES_H
//MACROS
# ifndef SHOW_MESSAGES
# define SHOW_MESSAGES 0
# endif
// Function Protoypes
int print_message(char *message, int speed, int delay);
int print_same_line(char *message, int speed, int delay);
int print_message_with_separator(char *message, int speed, int delay, char separator);
#endif
