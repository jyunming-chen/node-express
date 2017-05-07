#include <stdio.h>
#include <stdlib.h>  // for atof
#include <math.h>

void rose (double K, double t, double &x, double &y)
// K, t: call by value
// x, y: call by reference
{	
	x = cos (K*t)*cos(t);
	y = cos (K*t)*sin(t);
}

int main(int argc, char *argv[]) {
    if ( argc != 3 ) {
    	printf("%d", 0);
		exit (1);
    }else {
		double x, y;
		double K = atof (argv[1]);
    	double t = atof (argv[2]);
		rose (K, t, x, y);
        printf("%lf %lf", x, y);
    }
    exit(0);
}

