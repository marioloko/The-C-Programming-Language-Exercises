#include <stdio.h>
#define MAXLINE 1000 /* maximum input length */
#define MAXCOLUMS 50 /* max length of the short line format */

int getlinelength(char line[], int lim);
void divideline(char line[], int len, int columns);
int firstpreviousblank(char line[], int pos);
int lastblank(char line[], int pos);

/* Get a line and split it in shorter lines and print them */
main() {
	int len;			/* length of the current string */
	char line[MAXLINE]; /* current line where store the input */
	
	while ( (len = getlinelength(line, MAXLINE)) > 0 ) {
		divideline(line, len, MAXCOLUMS);
		printf("%s\n", line);
	}
}

/* getlinelength: store the input in the line enter as parameter, and return
*	the length of the string 
* line[] = the array where we want to store the input characters
* lim = the size of the line array
*/
int getlinelength(char line[], int lim) {
	int i, c;
	for ( i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i )
		line[i] = c;
	if ( c == '\n' ) {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

/* divideline: divide the line enter as parameter, into shorter lines with
*	maximum length equal to the parameter colums 
*	line[] = line that we want to divide in shorter lines
*	len = length of the line enter as parameter
*	colums = maximum number of character per line
*/
void divideline(char line[], int len, int colums) {
	int lc = 0; /* last character before the column limit */
	while ( ((len-lc) / colums) > 0 ) {
		lc = lc + colums;	
		lc = firstpreviousblank(line, lc);
		lc = lastblank(line, lc);
		line[lc] = '\n';
	}
}

/* firstpreviousblank: search the first blank in the line that is located in
*	the current position or before 
*	line[] = line where we want to search previous blanks
*	pos = position where start searching previous blanks
*	return the position of the first current or previous blank
*/ 
int firstpreviousblank(char line[], int pos) {
	while ( line[pos]!=' ' && line[pos]!='\t' && line[pos]!='\n' )
		--pos;
	return pos;
}

/* lastblank: search the last position of an space before a character
* line[] = line where we want to search the last blank
* pos = position from where we start searching
* return the position of the last blank before a character
*/
int lastblank(char line[], int pos) {
	while ( line[pos+1]==' ' && line[pos+1]!='\t' && line[pos+1]!='\n' )
		++pos;
	return pos;
}
