#include <stdio.h>
#define MAXLINE 1000 	/* maximum string length */
#define TABSTOPS 4 		/* set the number of space of each tab */
#define TAB	'\t'			/* tab character */
#define SPACE ' '			/* space character */

int getlinelength(char line[], int limit);
int copywithouttabs(char line[], char aux[], int length);
int replacetabs(char aux[], int auxpos);
void copy(char to[], char from[]);


/* Change tabs with blankspaces */
main() {
	int length;
	char line[MAXLINE];
	char aux[MAXLINE];

	while ( (length = getlinelength(line, MAXLINE)) > 0 ) {
		copywithouttabs(line, aux, length);
		copy(line, aux);
		printf("%s\n", line);
	}
}

/* getlinelength: read the input line and return the length */
int getlinelength(char line[], int limit ) {
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

/* copy: copy the content of from array to the to array */
void copy(char to[], char from[]) {
	int pos=0;
	while ( (to[pos] = from[pos]) != '\0' )
		pos++;
}

/* copywithouttabs: copy the line without tabs in an auxiliar array return 
		the new length */
int copywithouttabs(char line[], char aux[], int length) {
	int linepos, auxpos;
	for ( linepos=auxpos=0; linepos <= length; ++linepos )
		if ( line[linepos] == TAB ) 
			auxpos = replacetabs(aux, auxpos);
		else {
			aux[auxpos] = line[linepos];
			++auxpos;
		}
	return auxpos;
}

/* replacetabs:  replace tabs with the equivalent whitespaces return the new 
		pos in the line */
int replacetabs(char aux[], int tabpos) {
	int pos, limit;
	limit = tabpos + TABSTOPS;
	for ( pos=tabpos; pos < limit; ++pos )
		aux[pos] = SPACE;
	return limit;
}
