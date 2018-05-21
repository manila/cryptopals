#include "b64.h"

char *xor_string_char(char *str, char c, size_t str_len)
{
	char *out = (char *) malloc(sizeof(char) * str_len + 1);

	while (str_len--)
	{
		out[str_len] = c ^ str[str_len];
	}
	
	return (out);
}
