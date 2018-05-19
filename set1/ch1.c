#include "b64.h"

char *BASE64_CHAR_ARR = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char  	*hex_to_dec(char *hex_str, size_t str_len)
{
	unsigned int i = 0;
	char *dec = (char *) malloc(sizeof(char) * (str_len / 2));

	for (i = 0; i < str_len; i++)
	{
		sscanf(hex_str + (i * 2), "%2hhx", &dec[i]);
	}

	return (dec);
}

char	*dec_to_b64(char *dec, size_t len)
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

		buf[0] = ((dec[i + 0] & 0xfc) >> 2);
		buf[1] = ((dec[i + 0] & 0x03) << 4) | ((dec[i + 1] & 0xf0) >> 4); 
		buf[2] = ((dec[i + 1] & 0x0f) << 2) | ((dec[i + 2] & 0xc0) >> 6);
		buf[3] = ((dec[i + 2] & 0x3f));

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

int	main(void)
{

	char *in = "4D61";

	char *dec = hex_to_dec(in, strlen(in));
	char *b64 = dec_to_b64(dec, strlen(in) / 2);

	printf("%s", b64);	

	free(dec);
	free(b64);
	
	return (0);
}
