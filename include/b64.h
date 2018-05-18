#ifndef B64_H
# define B64_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void	Byte3asChar4(char *in, char *out);
void	Char2asByte1(char *in, char *out);
char	index_of(char *arr, char c);
char	Base16PairToChar(char *hex_pair);
char	*Base16toBase64(char *hexstr);

#endif
