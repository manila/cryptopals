#ifndef XOR_H
# define XOR_H

# include <stdlib.h>
# include <string.h>

char *xor_string(char *str, char *key, size_t str_len, size_t key_len);
int ham_char(char c1, char c2);
int ham_string(char *str1, char *str2, size_t str_len);
char *str_nth_block(char *str, int nth_block, int block_len, size_t str_len);
int detect_keysize(char *str, size_t str_len);

#endif
