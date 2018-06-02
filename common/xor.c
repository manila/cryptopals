#include "xor.h"
#include <stdio.h>

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

char *str_nth_block(char *str, int nth_block, int block_len, size_t str_len)
{
	int i = 0;
	char *str_block = (char *) malloc(sizeof(char) * block_len + 1);

	while (i < block_len)
	{
		str_block[i] = str[i + (block_len * (nth_block - 1))]; 
		i++;
	}
	
	str_block[block_len] = '\0';

	return (str_block);
}

int detect_keysize(char *str, size_t str_len)
{
	int keysize;
	int ham_dist = 37;
	int edit_dist = 2;
	char *tmp_block1 = NULL;
	char *tmp_block2 = NULL;

	int best_edit_dist = 40;
	int best_keysize = 40;

	for (keysize = 40; keysize > 0; keysize--)
	{
		tmp_block1 = str_nth_block(str, 1, keysize, str_len);
		tmp_block2 = str_nth_block(str, 2, keysize, str_len);

		ham_dist = ham_string(tmp_block1, tmp_block2, keysize);		

		edit_dist = ham_dist / keysize;
		
		if (edit_dist <= best_edit_dist)
		{
			best_edit_dist = edit_dist;
			best_keysize = keysize;
		}

		free(tmp_block1);
		free(tmp_block2);
	}
	
	return (best_keysize);	
}
