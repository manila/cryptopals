#include "b64.h"

int main(void)
{
	char *hex_str ="49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d\0";
	char *dec_str = decode_hex(hex_str, 96);
	char *b64_str = encode_b64(dec_str, 96 /2);
	char *hex_enc = encode_hex("Mani", 4);

	printf("\nChallenge 1: %s\n", b64_str);
	
	free(dec_str);
	free(b64_str);
	free(hex_enc);

	char *ch2_hex1 = "1c0111001f010100061a024b53535009181c\0";
	char *ch2_hex2 = "686974207468652062756c6c277320657965\0";
	char *ch2_str1 = decode_hex(ch2_hex1, 36); 
	char *ch2_str2 = decode_hex(ch2_hex2, 36);

	char *ch2_ans = xor_strings(ch2_str1, ch2_str2, 18);
	char *ch2_hex_ans = encode_hex(ch2_ans, 18);

	printf("\nChallenge 2: %s\n", ch2_hex_ans);

	return (0);
}
