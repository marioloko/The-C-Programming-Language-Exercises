#include <stdio.h>

float toCelsius(float fahrenheit);

/* Calculate celsius equivalent
		for fahr = 0,20,.., 300 */
main() {
	int fahr;

	for (fahr = 0; fahr <= 300; fahr = fahr + 20)
		printf( "%3f\n", toCelsius(fahr) );
}

/* Calculate the celsius equivalent to a given fahrenheit temperature */
float toCelsius(float fahrenheit) {
	return ( 5.0 / 9.0) * (fahrenheit - 32);
}
