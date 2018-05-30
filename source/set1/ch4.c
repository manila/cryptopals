#include "pals.h"

/*
 *  Return an array of strings read from file, a single string is read untill a newline or EOF is reached
 */
void	decrypt_me(char *str, size_t str_len);

dstr_list_t *read_strings_from_file(int fd)
{
	char char_buf;
	char str_buf[61];
	size_t str_len = 0;

	dstr_list_t *head = NULL;
	dstr_list_t *d_list = NULL;
	int stop = 1;

	while (read(fd, &char_buf, 1))
	{
		if ((char_buf != '\n') & (char_buf != '\0'))
		{
			str_buf[str_len++] = char_buf;
		}
		else
		{
			dstr_list_t *d_str = NULL;
	
			if (d_list == NULL)
			{
				head = d_list = create_list_item(d_str);
			}
			else
			{
				d_str = create_list_item(head);
			}

			str_buf[str_len] = '\0';

			memcpy(str_buf, d_str->hex, str_len + 1);

			str_len = 0;
		}
	}

	return (head);
}

void	decrypt_me(char *str, size_t str_len)
{
//	char *d_hex = decode_hex(str, str_len);
//	char *d_str = decrypt_string(str, str_len / 2);
	
	printf("%s \n", str);

//	free(d_hex);
//	free(d_str);
}
