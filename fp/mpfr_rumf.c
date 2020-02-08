#include<stdio.h>
#include<gmp.h>
#include<mpfr.h>
#define PRECISION 800
int main(void)
{
	unsigned int i;
        double b = 33096.0;
        double a = 77617.0;
        //mpfr_t b, b6, b8, a2, firstexpr;
        mpfr_t f, b2, b4, b6, b8, a2, firstexpr, expr, divisor, lastexpr;

	// start with 200 bits precision
        //mpfr_init2(b, PRECISION);
	//mpfr_set_d(b, 33096.0,MPFR_RNDD);

	mpfr_init2(f, PRECISION);
	mpfr_init2(b4, PRECISION);
	mpfr_init2(b6, PRECISION);
        mpfr_init2(b8, PRECISION);
        mpfr_init2(b2, PRECISION);
        mpfr_init2(divisor, PRECISION);
        mpfr_init2(lastexpr, PRECISION);
        mpfr_set_d(divisor,a,MPFR_RNDD);
        mpfr_init2(firstexpr, PRECISION);
        mpfr_init2(expr, PRECISION);
        mpfr_set_d(b4,1.0,MPFR_RNDD);
        mpfr_set_d(b6,1.0,MPFR_RNDD);
        mpfr_init2(b8, PRECISION);
        mpfr_set_d(b8,1.0,MPFR_RNDD);
        mpfr_set_d(b2,1.0,MPFR_RNDD);
        mpfr_init2(a2, PRECISION);
        mpfr_set_d(a2,1.0,MPFR_RNDD);
        mpfr_init2(firstexpr, PRECISION);
	for (i = 0; i < 8; i++) { 
		mpfr_mul_d(b8,b8,b,MPFR_RNDU);
                if ( i < 6 )
	            	mpfr_mul_d(b6,b6,b,MPFR_RNDU);
                if ( i < 4 )
	            	mpfr_mul_d(b4,b4,b,MPFR_RNDU);
		if ( i < 2 ) {
	            	mpfr_mul_d(b2,b2,b,MPFR_RNDU);
	            	mpfr_mul_d(a2,a2,a,MPFR_RNDU);
                }
	}
	printf("b8 is:");
	mpfr_out_str(stdout,10,0,b8,MPFR_RNDD);
	printf("\n");
	printf("b6 is:");
	mpfr_out_str(stdout,10,0,b6,MPFR_RNDD);
	printf("b2 is:");
	mpfr_out_str(stdout,10,0,b2,MPFR_RNDD);
        // calculate firstexpr
        mpfr_mul_d(firstexpr,a2,11.0,MPFR_RNDU);
        mpfr_mul(firstexpr,firstexpr,b2,MPFR_RNDU);
        mpfr_sub(firstexpr,firstexpr,b6,MPFR_RNDU);
	mpfr_mul_d(expr, b4,-121.0,MPFR_RNDU);
	printf("\n");
	printf("expr is:");
	mpfr_out_str(stdout,10,0,expr,MPFR_RNDD);
	printf("\n");
	printf("firstexpr before last op is:");
	mpfr_out_str(stdout,10,0,firstexpr,MPFR_RNDD);
        mpfr_sub(firstexpr,firstexpr,expr,MPFR_RNDU);
	printf("\n");
	printf("firstexpr is:");
	mpfr_out_str(stdout,10,0,firstexpr,MPFR_RNDD);
        mpfr_sub_d(firstexpr,firstexpr,-2.0,MPFR_RNDU);
	mpfr_mul_d(lastexpr,b8,5.5,MPFR_RNDU);
	mpfr_div_d(divisor,divisor,2*b,MPFR_RNDD);
	printf("divisor is:");
	mpfr_out_str(stdout,10,0,divisor,MPFR_RNDD);
	mpfr_add(lastexpr,lastexpr,divisor,MPFR_RNDD);	
	mpfr_mul(firstexpr,firstexpr,a2,MPFR_RNDD);
	mpfr_mul_d(f,b6,333.75,MPFR_RNDD);
	printf("\n");
	printf("First term:");
	mpfr_out_str(stdout,10,0,f,MPFR_RNDD);
	mpfr_add(f,f,firstexpr,MPFR_RNDD);
	mpfr_add(f,f,lastexpr,MPFR_RNDD);
	printf("\n");
	printf("Result is > ");
	mpfr_out_str(stdout,10,0,divisor,MPFR_RNDD);
	return 0;
}
