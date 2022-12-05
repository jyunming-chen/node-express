#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n*factorial(n-1);
}


int main(int argc, char *argv[]) {
		
    if ( argc != 2 ) {
		fprintf (stdout, "0\n");
		exit(1);
    }else {
		printf ( "%d", factorial( atoi(argv[1]) ) );
		exit(0);
    }
}

