#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char b16chars[] = "0123456789ABCDEF";
char b64chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int	htoi(char *hex_pair);
void	encode_block(unsigned char *in, unsigned char *out);

int	main(int argc, char **argv)
{
	int		i;
	unsigned char	out[4];
	unsigned char	man[4] = {77};
	
	encode_block(man, out);

	printf("%s", out);
	
	return (0);	
}

void	encode_block(unsigned char *in, unsigned char *out)
{
	out[0] = (unsigned char) b64chars[in[0] >> 2];
	out[1] = (unsigned char) b64chars[((in[0] & 0x03) << 4) | ((in[1] & 0xf0) >> 4)];
	out[2] = (unsigned char) ((in[1] & 0x0f) << 2) | ((in[2] & 0xc0) >> 6) > 0 ? b64chars[((in[1] & 0x0f) << 2) | ((in[2] & 0xc0) >> 6)] : '=';
	out[3] = (unsigned char) (in[2] & 0x3f) > 0 ? b64chars[(in[2] & 0x3f)] : '=';
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
	return (0);
}

unsigned char	hex_pair_to_dec(char *hex_pair)
{
	int	num;

	num = index_of(b16chars, *hex_pair);
	num = num << 4;
	num += index_of(b16chars, *(++hex_pair)); 

	return (num);
}

char	*hex_to_base64(char *hexstr)
{
	size_t		i;
	unsigned char	*base64str;

	i = 0;
	base64str = (unsigned char *) malloc(sizeof(unsigned char) * (4 * (strlen(hexstr) / 3)) + 1);
	while (hexstr[i] && hexstr[i + 1])
	{	
		i += 2;
	}
	return (base64str);
}
