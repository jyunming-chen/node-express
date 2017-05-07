#include <stdio.h>
#include <stdlib.h>  // for strtol
#include <math.h>

#define Sqr(x) ((x)*(x))
int main(int argc, char *argv[]) {
    if ( argc != 4 ) {
    	printf("%lf", 0.0);
    }else {
    	double len = sqrt (Sqr(atof(argv[1]))+Sqr(atof(argv[2]))+Sqr(atof(argv[3])));
        printf("%lf", len );
    }
    return 0;
}
