#include <stdio.h>

#define IN 1  /* Inside a word */
#define OUT 0 /* Outside a word */

main() {
	int c, state;

	state = OUT;

	while ( (c = getchar()) != EOF ) {
		if ( c == ' ' || c == '\n' || c == '\t' ) {
			if ( state == IN )
				putchar('\n');
			state = OUT;
		} else {
			putchar(c);
			state = IN;
		}
	}
}
