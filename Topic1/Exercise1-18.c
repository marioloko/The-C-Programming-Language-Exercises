#include <stdio.h>
#define MAXLENGTH 1000 /* Maximum line length */

int trimstr(char line[], int limit);

/* Deletes blanks and whitespaces of a given input line */
int main() {
	int length; 					/* length of the current word */	
	char line[MAXLENGTH]; /* Current line */
	
	while ( (length = trimstr(line, MAXLENGTH)) > 0 )
		printf("The line '%s' has length: %d\n", line, length);
	return 0;
}

/* trimstr: eliminate trailing blanks of an input line and return the length */
int trimstr(char line[], int limit) {
	int length = getlinelength(line, limit);
	return removetrailingspaces(line, length);
}

/* getlinelength: store the input in line and return the length */
int getlinelength(char line[], int limit) {
	int c, pos;

	for (pos=0; pos < limit-1 && (c=getchar())!=EOF && c!='\n'; pos++)
		line[pos] = c;
	if (c == '\n') {
		line[pos] = c;
		pos++;
	}
	line[pos] = '\0';
	return pos;
}

int removetrailingspaces(char line[], int length) {
	int c;
	while ( (c=line[length-1])==' ' || c=='\n' || c=='\t' ) {
		line[length-1] = '\0';
		length--;
	}
	return length;
}
