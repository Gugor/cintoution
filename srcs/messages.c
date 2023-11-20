# include "../includes/messages.h"
# include "../includes/game.h"

int print_message(char *message, int speed)
{
	int pos;

	pos = 0;

	if (!message || !message[0])
	{
		printf("No message passed\n");
		return (-1);
	}
	if (speed < 0)
		speed = 90000;
	while (*(message + pos))
	{
		if (write(1, &message[pos], 1) < 0)
		{
			perror("write message");
			return (-1);
		}	
		pos++;
		usleep(speed);
	}
	fflush(stdout);
	return (pos);
}


/**
 * Print a message in the same line
 * @param: message (char *) the message to print
 * @param: speed (int) the writing speed of the message
 */
int print_same_line(char *message, int speed)
{
	int pos;

	pos = 0;
	if (!message || !message[0])
	{
		printf("No message passed\n");
		return (0);
	}
	if (speed < 0)
		speed = 90000;
	while (*(message + pos))
	{
		if (write(1, &message[pos], 1) < 0)
		{
			perror("write message");
			return (-1);
		}	
		pos++;
		usleep(speed);
	}
	if (write(1, "\r\033[K", 5) < 0)
	{
			perror("write message");
			return (-1);
	}
	fflush(stdout);
	usleep(speed);
	return (pos);
}
