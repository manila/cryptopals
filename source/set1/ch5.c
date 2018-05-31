#include "pals.h"
#include "xor.h"
#include "b64.h"

void set_1_challenge_5(void)
{
	char in[] = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal\0";
	char key[] = "ICE";
	char *x_str = xor_string(in, key, strlen(in), 3);
	char *h_str = encode_hex(x_str, strlen(in));

	printf("\nChallenge 5: %s\n", h_str);	

	free(x_str);
	free(h_str);
}
