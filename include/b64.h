#ifndef B64_H
# define B64_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

extern char *B64_CHAR_ARR;

char *decode_hex(char *hex_str, size_t len);
char *encode_b64(char *in, size_t len); 

#endif
