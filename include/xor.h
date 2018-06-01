#ifndef XOR_H
# define XOR_H

# include <stdlib.h>
# include <string.h>

char *xor_string(char *str, char *key, size_t str_len, size_t key_len);
int ham_char(char c1, char c2);
int ham_string(char *str1, char *str2, size_t str_len);

#endif
