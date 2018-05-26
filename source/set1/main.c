#include "pals.h"

int main(int argc, char **argv)
{
	char *hex_str ="49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	char *dec_str = decode_hex(hex_str, 96);
	char *b64_str = encode_b64(dec_str, 96 /2);
	char *hex_enc = encode_hex("Mani", 4);

	printf("\nChallenge 1: %s\n", b64_str);
	
	free(dec_str);
	free(b64_str);
	free(hex_enc);

	char *ch2_hex1 = "1c0111001f010100061a024b53535009181c";
	char *ch2_hex2 = "686974207468652062756c6c277320657965";
	char *ch2_str1 = decode_hex(ch2_hex1, 36); 
	char *ch2_str2 = decode_hex(ch2_hex2, 36);

	char *ch2_ans = xor_strings(ch2_str1, ch2_str2, 18);
	char *ch2_hex_ans = encode_hex(ch2_ans, 18);

	printf("\nChallenge 2: %s\n", ch2_hex_ans);

	free(ch2_str1);
	free(ch2_str2);

	free(ch2_ans);
	free(ch2_hex_ans);

	char *ch3_hex = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
	char *ch3_str = decode_hex(ch3_hex, 68);
	char *d_str = decrypt_string(ch3_str, 34);

	printf("\nChallenge 3: Decrypted Text: %s\n", d_str); 	

	free(d_str);

	int fd;

	if (2 == argc)
	{
		fd = open(argv[1], O_RDONLY);

		char **strs = read_strings_from_file(fd);

		printf("%s", strs[1]);

		free(strs);

		close(fd);
	}	

	return (0);
}
