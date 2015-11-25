#include <stdio.h>

/* Write the fahrenheit equivalent
		for cels = 0, 20, ..., 300 */
main() {
		int cels;
		float fahr;
		int lower, upper, step;

		lower = 0; 	 /* Lower celsius degree */
		upper = 300; /* Upper celsius degree */
		step  = 20;  /* Transition step */

		cels = lower;
		while (cels <= upper) {
			fahr = ( (9.0 / 5.0) * cels ) + 32;
			printf("%3d\t%3.1f\n", cels, fahr);
			cels = cels + step;
		}
}
