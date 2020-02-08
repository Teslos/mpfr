#include<stdio.h>
#include<math.h>
long double shift_in_fp( long double a, long double b)
{
        long double big_number = powl(b, 6.0L) + powl(a, 2.0L)
                                   * ( 11.0L * powl(a, 2.0L)
                                       * powl(b, 2.0L)
                                       - powl(b, 6.0L)
                                       - 121.0L * powl(b, 4.0L) - 2.0L )
                                       + 5.5L * powl(b, 8.0L) + (a / (2.0L * b ) );
 
        long double shift_value = powl(2.0L, logl(fabsl(big_number)) / logl(2.0) );
 
        return ( 333.75L * shift_value * big_number / shift_value );
 
}


int main(int argc, char **argv) {
    long double a = 77617.0;
    long double b = 33096.0;
	printf("%-+32.28e\n\n", shift_in_fp(a,b));
	return 0;
}
