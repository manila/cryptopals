#include "b64.h"

char *BASE16_CHAR_ARR = "0123456789abcdef";
char *BASE64_CHAR_ARR = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char  	*decode_hex(char *hex_str, size_t str_len)
{
	unsigned int i;
	char *out = (char *) malloc(sizeof(char) * (str_len / 2));

	for (i = 0; i < (str_len / 2); i++)
	{
		sscanf(hex_str + (i * 2), "%2hhx", &out[i]);
	}

	return (out);
}

char	*encode_hex(char *str, size_t str_len)
{
	unsigned int i;
	
	char *hex_str = (char *) malloc(sizeof(char) * (str_len * 2) + 1);	
	
	for (i = 0; i < str_len; i++)
	{
		
		hex_str[(i * 2) + 0] = BASE16_CHAR_ARR[str[i] >> 4]; 
		hex_str[(i * 2) + 1] = BASE16_CHAR_ARR[str[i] & 0x0f];
	}

	hex_str[i * 2 + 1] = '\0';	

	return (hex_str);
}

char	*encode_b64(char *in, size_t len)
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int z = 0;
	size_t size = 0;
	unsigned char buf[4];
	char *b64 = (char *) malloc(size);

	for (i = 0; i < len; i += 3)
	{
		size += 4;

		b64 = (char *) realloc(b64, size * sizeof(char));

		buf[0] = ((in[i + 0] & 0xfc) >> 2);
		buf[1] = ((in[i + 0] & 0x03) << 4) | ((in[i + 1] & 0xf0) >> 4); 
		buf[2] = ((in[i + 1] & 0x0f) << 2) | ((in[i + 2] & 0xc0) >> 6);
		buf[3] = ((in[i + 2] & 0x3f));

		while (j < 4)
		{
			b64[z++] = BASE64_CHAR_ARR[buf[j++]];	
		}

		j = 0;
	}

	if ((i - len) > 0)
	{
		b64 = (char *) realloc(b64, size * sizeof(char));
		
		z -= (i - len);

		while (i > len)
		{
			b64[z++] = '=';
			i--;
		}
	}
	

	b64[size] = '\0';

	return (b64);
}
