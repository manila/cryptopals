#include "b64.h"

int main(void)
{
	char *hex_str ="49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	char *dec_str = decode_hex(hex_str, strlen(hex_str));
	char *b64_str = encode_b64(dec_str, strlen(dec_str));

	printf("%s", b64_str);
	
	free(dec_str);
	free(b64_str);

	return (0);
}
