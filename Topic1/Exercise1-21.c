#include <stdio.h>
#define MAXLINE 1000	/* max line length */
#define TABSTOP 4			/* max tab stop */
#define TAB '\t'			/* tab character */
#define SPACE ' '			/* space character */

#define true '1' 				/* boolean true */
#define false '\0'				/* boolean false */

int getlinelength(char line[], int limit);
void copy(char to[], char from[]);
int entab(char line[], char aux[], int length);
int spacescount(char line[], int tabpos);
int mintabs(int consecutivespaces);
int minblanks(int consecutivespaces);
int replacespaces(char aux[], int pos, int mintabs, int minblanks);
int consecutivechar(char line[], char c, int pos, int times);

main() {
	int length;			/* length of the current line */
	char line[MAXLINE];	/* current line string */
	char aux[MAXLINE]; 	/* auxiliar string */
	
	while ( (length=getlinelength(line, MAXLINE)) > 0) {
		length = entab(line, aux, length);
		copy(line, aux);
		printf("%s\n", line);
	}
	return 0;
}

/* getlinelength: save the input line and return its length */
int getlinelength(char line[], int limit) {
	int c, i;

	for ( i=0; i < limit-1 && (c=getchar())!=EOF && c!='\n'; ++i )
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

/* copy: copy the from array to the to array */
void copy(char to[], char from[]) {
	int i = 0;
	while ( (to[i] = from[i]) != '\0' )
		i++;
}

/* entab: change the spaces with the equivalent tabs return the new length*/
int entab(char line[], char aux[], int length) {
	int linepos, auxpos;
	for (linepos=auxpos=0; linepos <= length;)
		if ( line[linepos] == SPACE ) {
			int tabs, blanks, limit;
			blanks = spacescount(line, linepos);	
			linepos = linepos + blanks;
			auxpos = replacespaces(aux, auxpos, mintab(blanks),
						minblanks(blanks) );
		} else {
			aux[auxpos] = line[linepos];
			++linepos;
			++auxpos;
		}
	return auxpos;
}

/* spacescount: count the number of consecutive spaces */
int spacescount(char line[], int tabpos) {
	int nb;
	for ( nb = 0; line[nb + tabpos] == SPACE; ++nb)
		;
	return nb;
}

/* mintab: return the minimum number of tabs for that tabstop */
int mintab(int consecutiveblanks) {
	return consecutiveblanks / TABSTOP;
}

/* minblanks: return the minimum number of blanks for that tabstop */
int minblanks(int consecutiveblanks) {
	return consecutiveblanks % TABSTOP;
}

/* replacespaces: replace spaces with the minimal number of combination of
	spaces and tabs, return the next character position */
int replacespaces(char aux[], int pos, int mintabs, int minblanks) {
	pos = consecutivechar(aux, TAB, pos, mintabs);	
	pos = consecutivechar(aux, SPACE, pos, minblanks);	
	return pos;
}

/* consecutivechar: write in the line the character c, 
	several times(the indicated in the times variable, starting from the 
	position pos, return the first blank position of the line */
int consecutivechar(char line[], char c, int pos, int times) {
	int i, limit = pos + times;
	for ( i = pos; i < limit; i++ )	
		line[i] = c;
	return limit;
}
