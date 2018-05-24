#include "pals.h"

char *ALPHA_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
size_t ALPHA_CHARS_COUNT = 52;
char *VOWEL_CHARS = "aAeEiIoOuU";
size_t VOWEL_CHARS_COUNT = 10;

int count_char(char *str, char c, size_t str_len);
int count_chars(char *str, size_t str_len, char *chars, size_t chars_len);
dstr_list_t *sort_list_by_score(dstr_list_t *list);
dstr_list_t *get_best_decryption(dstr_list_t *list);

char *xor_string_char(char *str, char c, size_t str_len)
{
	char *out = (char *) malloc(sizeof(char) * str_len + 1);

	out[str_len] = '\0';

	while (str_len--)
	{
		out[str_len] = c ^ str[str_len];
	}	

	return (out);
}

/*
return a list sorted by highest scoring decryption first
*/

dstr_list_t *decrypt_string(char *str, size_t str_len)
{
	unsigned int i;

	dstr_list_t *head = NULL;
	dstr_list_t *d_list = NULL;

	for (i = 0; i < 52; i++)
	{	
		dstr_list_t *d_str;
		d_str = (dstr_list_t *) malloc(sizeof(dstr_list_t));

		d_str->encrypted = (char *) malloc(sizeof(char) * str_len + 1);
		d_str->encrypted = str;

		d_str->decrypted = xor_string_char(str, ALPHA_CHARS[i], str_len);

		d_str->key = ALPHA_CHARS[i];
		d_str->length = str_len;
		d_str->space_count = count_char(d_str->decrypted, ' ', str_len);
		d_str->alpha_count = count_chars(d_str->decrypted, str_len, ALPHA_CHARS, ALPHA_CHARS_COUNT);
		d_str->vowel_count = count_chars(d_str->decrypted, str_len, VOWEL_CHARS, VOWEL_CHARS_COUNT);

		d_str->score = d_str->space_count + d_str->alpha_count + d_str->vowel_count;		

		if (d_list == NULL)
		{
			head = d_list = d_str;
		}
		else
		{
			d_list->next = d_str;
			d_list = d_list->next;
		}
	}

	return (get_best_decryption(head));
}

int printable_char_count(char *str, size_t str_len)
{
	int count = 0;
	
	while (str_len--)
	{
		if (str[str_len] > 31 && str[str_len] < 127)
		{
			count++;
		}
	}

	return count;
}

/*
return the number of times char c shows up in char *str
*/

int count_char(char *str, char c, size_t str_len)
{
	int count = 0;

	while (str_len--)
	{
		if (str[str_len] == c)
		{
			count++;
		}
	}

	return count;
}

int count_chars(char *str, size_t str_len, char *chars, size_t chars_len)
{
	unsigned int i;
	unsigned int j;
	int count = 0;

	for (i = 0; i < chars_len; i++)
	{
		for (j = 0; j < str_len; j++)
		{
			if (str[j] == chars[i])
			{
				count++;
			}
		}
	}

	return (count);
}

dstr_list_t *get_best_decryption(dstr_list_t *list)
{
	dstr_list_t *tmp = NULL;
	dstr_list_t *tmp_next = NULL;
	dstr_list_t *best = NULL;
	dstr_list_t *head = NULL;

	head = list;
	best = list;

	while (list->next != NULL)
	{
		if (list->score > best->score)
		{
			tmp = best;	
			best = list;
			tmp_next = best->next;
			best->next = list->next;
			list = tmp;
			list->next = tmp_next;
		}

		list = list->next;
	}

	return (best);
}

dstr_list_t *sort_list_by_score(dstr_list_t *list)
{
	dstr_list_t *head = get_best_decryption(list);
	dstr_list_t *tmp = NULL;	
}

void	free_dstr_list (dstr_list_t *list)
{
	dstr_list_t *tmp = list->next;

	while (list->next != NULL)
	{
		tmp = list->next;
		free(list->decrypted);
		free(list->encrypted);
		free(list);
		list = tmp;
	}
}
