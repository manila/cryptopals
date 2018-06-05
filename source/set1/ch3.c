#include "pals.h"
#include "xor.h"

char *ALPHA_CHARS = " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
size_t ALPHA_CHARS_COUNT = 53;
char *VOWEL_CHARS = "aAeEiIoOuU";
size_t VOWEL_CHARS_COUNT = 10;
char *PUNCT_CHARS = ".,?!'";
size_t PUNCT_CHARS_COUNT = 5;
char *TOP10_CHARS = "eEtTaAoOiInNsShHrRdD";
size_t TOP10_CHARS_COUNT = 20;

int count_char(char *str, char c, size_t str_len);
int count_chars(char *str, size_t str_len, char *chars, size_t chars_len);
int score_string(char *str, size_t str_len);
dstr_list_t *sort_list_by_score(dstr_list_t *list);
dstr_list_t *get_best_decryption(dstr_list_t *list);
dstr_list_t *create_list_item(dstr_list_t *head);

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

cipher_struct_t  *decrypt_caesar(char *str, size_t str_len)
{
	cipher_struct_t *cipher_data = (cipher_struct_t *) malloc(sizeof(cipher_struct_t));
	cipher_data->plaintext = (char *) malloc(sizeof(char) * str_len + 1);

	char *decrypted_temp = (char *) malloc(sizeof(char) * str_len + 1);
	int  score_temp = 0;
	int  score_best = 0;

	unsigned char key;

	for (key = 32; key < 127; key++)
	{	
		decrypted_temp[str_len] = '\0';
		decrypted_temp = xor_string_char(str, (char) key, str_len);

		score_temp = score_string(decrypted_temp, str_len);

		if (score_temp > score_best)
		{
			score_best = score_temp;
			cipher_data->key = (char) key;
			memcpy(cipher_data->plaintext, decrypted_temp, str_len);
		}		

	}

	free(decrypted_temp);

	cipher_data->plaintext[str_len] = '\0';

	return (cipher_data);
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

int score_string(char *str, size_t str_len)
{
	int vowel_count;
	int space_count;
	int top10_count;
	int alpha_count;
	int punct_count;	
	int print_count;

	space_count = count_char(str, ' ', str_len);
	vowel_count = count_chars(str, str_len, VOWEL_CHARS, VOWEL_CHARS_COUNT);
	alpha_count = count_chars(str, str_len, ALPHA_CHARS, ALPHA_CHARS_COUNT);
	top10_count = count_chars(str, str_len, TOP10_CHARS, TOP10_CHARS_COUNT);
	punct_count = count_chars(str, str_len, PUNCT_CHARS, PUNCT_CHARS_COUNT);
	print_count = printable_char_count(str, str_len);

	return (space_count + vowel_count + alpha_count + top10_count + punct_count + print_count);
}


dstr_list_t *get_best_decryption(dstr_list_t *list)
{
	dstr_list_t *best = NULL;

	best = list;

	while (list->next != NULL)
	{
		if (list->score > best->score)
		{
			best = list;
		}

		list = list->next;
	}

	return (best);
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

dstr_list_t *create_list_item(dstr_list_t *head)
{
	dstr_list_t *item;

	item = (dstr_list_t *) malloc(sizeof(dstr_list_t));

	if (item == NULL)
	{
		printf("Can't allocate memory for new list item");
		
		return (item);
	}
	
	if (head != NULL)
	{
		if (head->next == NULL)
		{
			head->next = item;
		}
		else
		{
			while (head->next != NULL)
			{
				head = head->next;
			}

			head->next = item;
		}
	}

	return (item);
}
