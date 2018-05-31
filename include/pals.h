#ifndef PALS_H
# define PALS_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h> 

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
	char hex[61];
	int space_count;
	int vowel_count;
	int alpha_count;
	int score;
	size_t length;
	struct dstr_list *next;
} dstr_list_t;

void		free_dstr_list(dstr_list_t *list);
char 		*decrypt_string(char *str, size_t str_len);
dstr_list_t	*read_strings_from_file(int fd);
dstr_list_t	*create_list_item(dstr_list_t *head);
dstr_list_t	*get_best_decryption(dstr_list_t *head);
int		score_string(char *str, size_t str_len);

void	set_1_challenge_5(void);

#endif
