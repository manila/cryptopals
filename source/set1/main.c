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

	printf("\nChallenge 3: Decrypted Text: %s score: %d\n", d_str, score_string(d_str, 34)); 	

	free(d_str);
	free(ch3_str);

	if (3 == argc)
	{
		int ch4_fd;

		ch4_fd = open(argv[1], O_RDONLY);

		dstr_list_t *d_list = read_strings_from_file(ch4_fd);
		dstr_list_t *d_list_head = (dstr_list_t *) d_list;

		while (d_list->next != NULL)
		{
			char *ch4_str = decode_hex(d_list->hex, d_list->length);

			d_list->decrypted = decrypt_string(ch4_str, d_list->length / 2);
			d_list->score = score_string(d_list->decrypted, d_list->length / 2);
	
			free(ch4_str);


			d_list = d_list->next;
		}

		printf("\nChallenge 4: Decrypted Text: %s\n", get_best_decryption(d_list_head)->decrypted);

		close(ch4_fd);
	}	

	set_1_challenge_5();

	if (2 == argc)
	{
		char *buffer[256];
		char *b64_file = NULL;
		int ch6_fd;
		int total_size = 0;
		int bytes_read = 0;

		ch6_fd = open(argv[1], O_RDONLY);

		while (bytes_read = read(ch6_fd, &buffer, 256))
		{
			b64_file = (char *) realloc(b64_file, sizeof(char) * (total_size + bytes_read));
		
			memcpy(&b64_file[total_size], buffer, bytes_read);
			
			total_size += bytes_read;
		}
		
		char *ch6_data = decode_b64(b64_file, total_size);

		printf("\nkeysize: %d\n", detect_keysize(ch6_data, (total_size / 3) * 4));
	}

	return (0);
}
