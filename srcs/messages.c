# include "../includes/messages.h"
# include "../includes/game.h"

static int print_separator(char separator)
{
		if (separator)
		{
			if (write(1, &separator, 1) < 0)
			{
				perror("write message");
				return (-1) ;
			}	
		}
		return (0);
}

int print_message(char *message, int speed, int delay)
{
	int pos;

	pos = 0;

	if (!SHOW_MESSAGES)
		return (0);

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
	sleep(delay);
	fflush(stdout);
	return (pos);
}

int print_message_with_separator(char *message, int speed, int delay, char separator)
{
	int pos;

	pos = 0;
/*
	if (!SHOW_MESSAGES)
		return (0);
*/
	if (!message || !message[0])
	{
		printf("No message passed\n");
		return (-1);
	}
	if (speed < 0)
		speed = 90000;
	while (*(message + pos))
	{
		
		print_separator(separator);
		if (write(1, &message[pos], 1) < 0)
		{
			perror("write message");
			return (-1);
		}	
		pos++;
		usleep(speed);
	}
	print_separator(separator);
	sleep(delay);
	fflush(stdout);
	return (pos);
}


/**
 * Print a message in the same line
 * @param: message (char *) the message to print
 * @param: speed (int) the writing speed of the message
 */
int print_same_line(char *message, int speed, int delay)
{
	int pos;

	pos = 0;

	if (!SHOW_MESSAGES)
		return (0);

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
	sleep(delay);
	return (pos);
}
