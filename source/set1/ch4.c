#include "pals.h"

/*
 *  Return an array of strings read from file, a single string is read untill a newline or EOF is reached
 */

dstr_list_t *read_strings_from_file(int fd)
{
	char char_buf;
	char str_buf[61];
	size_t str_len = 0;

	dstr_list_t *head = NULL;
	dstr_list_t *d_list = NULL;

	while (read(fd, &char_buf, 1))
	{
		if ((char_buf != '\n') & (char_buf != '\0'))
		{
			str_buf[str_len++] = char_buf;
		}
		else
		{
			dstr_list_t *d_str = (dstr_list_t *) malloc(sizeof(dstr_list_t));
			
			if (d_str == NULL)
			{
				printf("Could not allocate for struct");
			}						

			str_buf[str_len] = '\0';

			memcpy(d_str->hex, str_buf, str_len + 1);

			d_str->length = str_len;
	
			if (head == NULL)
			{
				head = d_list = d_str;
			}
			else
			{
				d_list = d_list->next = d_str;
			}
	
			str_len = 0;
		}
	}

	return (head);
}

