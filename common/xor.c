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

int ham_char(char c1, char c2)
{
	int ham_dist = 0;
	char c3 = c1 ^ c2;

	while (c3 != 0)
	{
		ham_dist++;
		c3 &= c3 - 1;
	}

	return (ham_dist);
}

int ham_string(char *str1, char *str2, size_t str_len)
{
	int ham_dist = 0;

	while (str_len--)
	{
		ham_dist += ham_char(str1[str_len], str2[str_len]);
	}

	return (ham_dist);
}
