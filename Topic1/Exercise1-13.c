#include <stdio.h>
#define IN 1  /* Inside the word */
#define OUT 0 /* Outside the word */

/* Print and histogram with the length of the input words */
main() {
	int c, wordlength, state, pos, innerpos;
	int lengths[100];

	for ( pos = 0; pos < 100; pos++ )
		lengths[pos] = 0;
	
	state = OUT;
	wordlength = 0;
	while ( (c = getchar()) != EOF) {
		if ( c == ' ' || c == '\t' || c == '\n' ) {
			if (state == IN) 
				lengths[wordlength]++;
			state = OUT;
		} else if(state == OUT) {
			state = IN;
			wordlength = 1;
		} else {
			wordlength++;
		}
	}

	for ( pos = 0; pos < 100; pos++) {
		printf("%3d|", pos);
		for ( innerpos = 0; innerpos < lengths[pos]; innerpos++)
			printf("=");
		printf("\n");
	}
}
