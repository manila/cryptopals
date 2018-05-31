#include "xor.h"

char *xor_string(char *str, char *key, size_t str_len, size_t key_len)
{
	unsigned int i;
	unsigned int j;
	char *out = (char *) malloc(sizeof(char) * str_len + 1);

	for (i = 0; i < str_len; i++)
	{
		out[i] = str[i] ^ key[j++];
		
		if (j >= (unsigned int) key_len)
		{
			j = 0;
		}
	}

	return (out);
}
