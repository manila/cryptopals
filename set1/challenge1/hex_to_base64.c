#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	check_valid_pairs(char *hexstr);

int	main(int argc, char **argv)
{
	int	i;
	int	total_len;
	char	*base64_str;
	
	i = 0;
	base64_str = (char *)malloc((sizeof(char) * total_len));
	if (argc != 2)
		return (0);
	else if (!check_valid_pairs((char *) argv[1]))
		return (0);
		
	total_len = strlen(argv[1]);
	while (i < total_len)
	{	
		i += 2;
	}
	
	printf("%d", argc);
	return (0);	
}

int	hex_to_dec(char *hex)
{
}

int	dec_to_base64(int dec)
{
}

int	check_valid_pairs(char *hexstr)
{
	return ((strlen(hexstr) % 2) == 0); 
}
