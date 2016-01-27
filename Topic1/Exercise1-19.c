#include <stdio.h>

void reverse(char string[]);
void copybackward(char string[], int length);

/* Print three words and then reverse it */
main (){
	char first[] = "first";
	char second[] = "second";
	char third[] = "third";
	printf("%s %s %s\n", first, second, third);

	reverse(first);
	reverse(second);
	reverse(third);

	printf("%s %s %s\n", first, second, third);
	return 0;
}

/* reverse: reverse the string enter as parameter */
void reverse(char string[]) {
	int length = getlength( string );
	copybackward(string, length);
}	

/* getlength: return the length of the string enter as parameter */
int getlength(char string[]) {
	int length = 0;
	while ( string[length] != '\0' )
		length++;
	return length;
}

/* copybackward: copy the array in reverse way */
void copybackward(char string[], int length) {
	int leftpos; 	/* Left char position for reversing */
	int rightpos; /* Right char position for reversing */
	for ( leftpos=0; leftpos < (rightpos = length-leftpos-1); leftpos++ ) {
		char aux = string[leftpos];
		string[leftpos] = string[rightpos];
		string[rightpos] = aux;
	}
}
