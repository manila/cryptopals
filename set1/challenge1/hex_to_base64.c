#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char b16chars[] = "0123456789ABCDEF";
char b64chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void	*Byte3asChar4(unsigned char *in, unsigned char *out)
{
	out[0] = (unsigned char) b64chars[in[0] >> 2];
	out[1] = (unsigned char) b64chars[((in[0] & 0x03) << 4) | ((in[1] & 0xf0) >> 4)];
	out[2] = (unsigned char) ((in[1] & 0x0f) << 2) | ((in[2] & 0xc0) >> 6) > 0 ? b64chars[((in[1] & 0x0f) << 2) | ((in[2] & 0xc0) >> 6)] : '=';
	out[3] = (unsigned char) (in[2] & 0x3f) > 0 ? b64chars[(in[2] & 0x3f)] : '=';
}

void	*Char2asByte1(unsigned char *in, unsigned char *out)
{
	out[0] = (unsigned char) ((in[0] & 0x0f) << 4) | (in[1] & 0x0f); 
}

unsigned char	index_of(char *arr, char c)
{
	int i;

	i = 0;
	while (arr[1])
	{
		if (arr[i] == c)
			return ((unsigned char) i);
		i++;
	}
	return (0);
}

unsigned char	Base16PairToChar(char *hex_pair)
{
	unsigned char	out;
	unsigned char	in[2];
	
	in[0] = index_of(b16chars, hex_pair[0]);
	in[1] = index_of(b16chars, hex_pair[1]);

	Char2asByte1(in, &out);

	return (out);
}

char		*Base16toBase64(char *hexstr)
{
	int		paddedlen;
	size_t		i;
	unsigned char	*base64str;
	
	i = 0;
	paddedlen = strlen(hexstr);
	
	while ((paddedlen * 8) % 6 != 0)
	{
		paddedlen++;
	}
	
	base64str = (unsigned char *) malloc(sizeof(unsigned char) * (4 * (paddedlen / 3)) + 1);

	while (hexstr[i] && hexstr[i + 1])
	{	
		printf("%d", Base16PairToChar(&hexstr[i]));
		i += 2;
	}
	return (base64str);
}


int		main(int argc, char **argv)
{
	Base16toBase64("4D616E");	
	return (0);	
}
