#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char b16chars[] = "0123456789ABCDEF";

void	htoi(char *hex_pair);

int	main(int argc, char **argv)
{
	htoi("4F");
	return (0);	
}

int	index_of(char *arr, char c)
{
	int i;

	i = 0;
	while (arr[1])
	{
		if (arr[i] == c)
			return (i);
		i++;
	}
	return (NULL);
}

void	htoi(char *hex_pair)
{
	int num;
	
	num = 0;
	while (*hex_pair)
	{
		num = num << 4;
		num += index_of(b16chars, *hex_pair);
		hex_pair++;
	}
	printf("\n%d\n", num);
}
