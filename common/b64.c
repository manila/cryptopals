#include "b64.h"

char *BASE16_CHAR_ARR = "0123456789abcdef";
char *BASE64_CHAR_ARR = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int	b64_char_index(char c)
{
	int i = 0;
	
	while (i < 64)
	{
		if (BASE64_CHAR_ARR[i] == c)
		{
			return (i);
		}
		else
		{
			i++;
		}
	}	
	
	return (0);
}

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

char	*encode_b64(char *str, size_t len)
{
	unsigned int i = 0;
	size_t size = 0;
	char *in = (char *) calloc(len, sizeof(char));
	char *b64 = NULL;

	memcpy(in, str, len);

	while (len % 3 != 0)
	{
		len++;
		in = realloc(in, sizeof(char) * len);
	}

	for (i = 0; i < len; i += 3)
	{
		size += 4;

		b64 = (char *) realloc(b64, size * sizeof(char) + 1);

		b64[size - 4] = BASE64_CHAR_ARR[((in[i + 0] & 0xfc) >> 2)];
		b64[size - 3] = BASE64_CHAR_ARR[((in[i + 0] & 0x03) << 4) | ((in[i + 1] & 0xf0) >> 4)]; 
		b64[size - 2] = BASE64_CHAR_ARR[((in[i + 1] & 0x0f) << 2) | ((in[i + 2] & 0xc0) >> 6)];
		b64[size - 1] = BASE64_CHAR_ARR[((in[i + 2] & 0x3f))];
	}

	if (!b64_char_index(b64[size - 1]))
	{
		b64[size - 1] = '=';

		if (!b64_char_index(b64[size - 2]))
		{
			b64[size - 2] = '=';
		} 	
	}

	b64[size] = '\0';

	return (b64);
}

char	*decode_b64(char *in, size_t len)
{
	unsigned int size = 0;
	unsigned int i;
	char *raw_data = NULL;	

	for (i = 0; i < len; i += 4)
	{
		size += 3;
		
		raw_data = (char *) realloc(raw_data, sizeof(char) * size + 1);	
	
		raw_data[size - 3] = (b64_char_index(in[i + 0]) << 2) | (b64_char_index(in[i + 1]) >> 4);
		raw_data[size - 2] = (b64_char_index(in[i + 1]) << 4) | (b64_char_index(in[i + 2]) >> 2);
		raw_data[size - 1] = (b64_char_index(in[i + 2]) << 6) | (b64_char_index(in[i + 3]));
	}

	if (raw_data[size - 1] == 0)
	{
		raw_data[size - 1] = '\0';
	
		if (raw_data[size - 2] == '\0')
		{
			raw_data[size - 2] = '\0';
		}
	}

	raw_data[size] = '\0';
	
	return (raw_data);
}
