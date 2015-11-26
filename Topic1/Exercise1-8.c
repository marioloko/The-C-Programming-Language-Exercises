#include <stdio.h>

/* Count blank, tabulations and new lines */
main(){
	int c, nb;

	nb = 0;
	while ( (c = getchar()) != EOF )
		if ( c == ' ' || c == '\t' || c == '\n' ) 
			nb++;
	printf("%d\n", nb);
}
