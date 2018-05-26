#include "pals.h"

/*
 *  Return an array of strings read from file, a single string is read untill a newline or EOF is reached
 */

size_t BUFF_SIZE = 61;

char **read_strings_from_file(int fd)
{
	// For conveince read the first 61 characters at a time, a shortcut to constuct 60 char strings
	char buffer[BUFF_SIZE];
	int str_count = 0;

	char **strings = NULL;
	
	while (read(fd, buffer, BUFF_SIZE))
	{

		str_count++;

		strings = (char **) realloc(strings, sizeof(char *) * str_count);
		
		strings[str_count] = (char *) malloc(sizeof(char) * BUFF_SIZE);

		memcpy(strings[str_count - 1], buffer, BUFF_SIZE);

		strings[str_count - 1][BUFF_SIZE] = '\0';
	}	

	return (strings);
}
