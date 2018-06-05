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

char **transpose_str(char *str, int block_count, int str_len)
{
	unsigned int i;
	char **cipher_block = (char **) malloc(sizeof(char *) * block_count);	
	char **array_start = cipher_block;

	for (i = 0; i < block_count; i++)
	{
		cipher_block[i] = (char *) malloc(sizeof(char) * (str_len / block_count) + 1);
		cipher_block[str_len / block_count] = '\0';
	}

	for (i = 0; i < str_len; i++)
	{
		cipher_block[i % block_count][i / block_count] = str[i];
	}

	return (array_start);
}

int detect_keysize(char *str, size_t str_len)
{
	int keysize;
	int ham_dist;
	int edit_dist;
	unsigned int i;
	unsigned int j;
	char *tmp_block[4] = {NULL, NULL, NULL, NULL};

	int best_edit_dist = 40;
	int best_keysize = 40;

	for (keysize = 40; keysize > 0; keysize--)
	{
		edit_dist = 0;
		ham_dist = 0;
	
		for (i = 0; i < 4; i++)
		{
			tmp_block[i] = (char *) realloc(tmp_block[i], sizeof(char) * keysize + 1); 
			tmp_block[i] = str_nth_block(str, i + 1, keysize, str_len);
		}
		
		for (i = 0; i < 4; i++)
		{
			for (j = i + 1; j < 4; j++)
			{
				ham_dist += ham_string(tmp_block[i], tmp_block[j], keysize);	
				edit_dist += ham_dist / keysize;
			}
		}

		edit_dist /= 6;
		
		if (edit_dist <= best_edit_dist)
		{
			best_edit_dist = edit_dist;
			best_keysize = keysize;
		}

		for (i = 0; i < 4; i++)
		{
			free(tmp_block[i]);
		}
	}
	
	return (best_keysize);	
}

char *detect_key(char *str, size_t keysize, size_t str_len)
{
	int  block_len = str_len / keysize;
	char *key;
	unsigned int i;

	key = (char *) malloc(sizeof(char) * keysize + 1);

	char **cipher_block = transpose_str(str, keysize, str_len);

	for (i = 0; i < keysize; i++)
	{
		cipher_struct_t *cipher_data = decrypt_caesar(cipher_block[i], str_len / keysize);
		key[i] = cipher_data->key;
		printf("\n Decrypted: %s \n", cipher_data->plaintext);
	}

	key[keysize] = '\0';	

	return (key);
}

