#include "b64.h"

char	*xor_strings(char *str1, char *str2, size_t str_len)
{
	char *out = (char *) malloc(sizeof(char) * str_len + 1);
	
	while (str_len--)
	{
		out[str_len] = str1[str_len] ^ str2[str_len];
	}

	out[str_len] = '\0';

	return (out);
}
