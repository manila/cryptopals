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
	unsigned char out[4];
	unsigned char man[3] = {77, 97, 110};
	
	encode_block(man, out);

	printf("%d", out[0]);
	
	return (0);	
}

void	encode_block(unsigned char *in, unsigned char *out)
{
	out[0] = in[0] >> 2;
	out[1] = ((in[0] & 0x03) << 4) | ((in[1] & 0xf0) >> 4);
	out[2] = ((in[1] & 0x0f) << 2) | ((in[2] & 0xc0) >> 6);
	out[3] = (in[2] & 0x03);
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

int	htoi(char *hex_pair)
{
	int	num;

	num = index_of(b16chars, *hex_pair);
	num = num << 4;
	num += index_of(b16chars, *(++hex_pair)); 

	printf("\n%d\n", num);
	return (num);
}
