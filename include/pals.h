#ifndef PALS_H
# define PALS_H

# include <stdio.h>

# include "b64.h"
# include "xor.h"

/*
 * Decrypted String List Struct. Linked list ordederd by highest scoring decryption first 
 */

typedef struct dstr_list
{
	char most_common_char;
	char *encrypted;
	char *decrypted;
	char key;
	int space_count;
	int vowel_count;
	int alpha_count;
	int score;
	size_t length;
	struct dstr_list *next;
} dstr_list_t;

dstr_list_t *decrypt_string(char *str, size_t str_len);

#endif
