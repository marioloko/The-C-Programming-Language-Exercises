#include <stdio.h>

/* Replace multiple blank strings for only one string */
int main() {
		int previousCharacter, currentCharacter;

		previousCharacter = ' ';
		while ( (currentCharacter = getchar()) != EOF ) {
				if ( !isspace(previousCharacter) || !isspace(currentCharacter) )
						putchar(currentCharacter);
				previousCharacter = currentCharacter;
		}
}
