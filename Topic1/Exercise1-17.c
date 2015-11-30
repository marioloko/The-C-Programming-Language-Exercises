#include <stdio.h>
#define MAXLINE 1000 /* Max length of one line */
#define PRINTLENGTH 80 /* Min length of a line for being printed */
#define MAXVALID 100   /* Max number of lines for printing */

int getlinelength(char line[], int limit);

/* Print lines with length larger than PRINTLENGTH */
int main() {
	int length;									/* Length of the current line */
	char line[MAXLINE];					/* Current line */

	while ( (length = getlinelength( line, MAXLINE )) > 0 )
		if ( length > PRINTLENGTH ) 
			printf("Larger than %d: %s", PRINTLENGTH, line);
}
	
/* getlinelength: fill the line enter as parameter with characters enter as 
		input and return the length of the line */
int getlinelength(char line[], int limit) {
	int c, length;
	
	for (length=0; length < limit-1 && (c = getchar())!=EOF && c!='\n'; ++length)
		line[length] = c;
	if (c == '\n') {
		line[length] = c;
		length++;
	}
	line[length] = '\0';
	return length;
}
