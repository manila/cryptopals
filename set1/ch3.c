#include "b64.h"

char *CHAR_ARR = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char *COMMON_CHAR = " eEtRaAoOiInNsShHrRdDlLcCuUmMwWfFgGyYpPbBvVkKjJxXqQzZ";

char *xor_string_char(char *str, char c, size_t str_len)
{
	char *out = (char *) malloc(sizeof(char) * str_len + 1);

	while (str_len--)
	{
		out[str_len] = c ^ str[str_len];
	}
	
	return (out);
}

/*
return an array of the highest scoring decrypted terminated strings acording to character frequency
*/

char **decrypt_string(char *str, size_t str_len)
{
	unsigned int i;
	char **str_arr;
	
	str_arr = (char **) malloc(sizeof(*str_arr) * 52);

	/* Each letter is a potential key, allocate 52 strings to correspond with ascii A-z */	
	for (i = 0; i < 52; i++)
	{
		str_arr[i] = malloc(sizeof(char) * (str_len + 1));
		
		str_arr[i] = xor_string_char(str, CHAR_ARR[i], str_len);

		str_arr[i][str_len] = '\0';
	}
	
	return (str_arr);
}

char *char_frequency(char *str, size_t str_len)
{
}

int printable_char_count(char *str, char c, size_t str_len)
{
}

/*
return the number of times char c shows up in char *str
*/

int count_char(char *str, char c, size_t str_len)
{
}
