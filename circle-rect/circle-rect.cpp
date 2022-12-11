/* 
Fast Circle-Rectangle Intersection Checking
by Clifford A. Shaffer
from "Graphics Gems", Academic Press, 1990
*/

#include "graphicsgems.h"
#include <stdlib.h>
#include <stdio.h>

//boolean Check_Intersect(R, C, Rad)
/* Return TRUE iff rectangle R intersects circle with centerpoint C and
   radius Rad. */
static boolean Check_Intersect(
 Box2 *R,
 Point2 *C,
 double Rad)
{
 double Rad2;

 Rad2 = Rad * Rad;
 /* Translate coordinates, placing C at the origin. */
 R->max.x -= C->x;  R->max.y -= C->y;
 R->min.x -= C->x;  R->min.y -= C->y;

 if (R->max.x < 0) 			/* R to left of circle center */
   	if (R->max.y < 0) 		/* R in lower left corner */
     		return ((R->max.x * R->max.x + R->max.y * R->max.y) < Rad2);
   	else if (R->min.y > 0) 	/* R in upper left corner */
     		return ((R->max.x * R->max.x + R->min.y * R->min.y) < Rad2);
   	else 					/* R due West of circle */
     		return(ABS(R->max.x) < Rad);
 	else if (R->min.x > 0)  	/* R to right of circle center */
   		if (R->max.y < 0) 	/* R in lower right corner */
     			return ((R->min.x * R->min.x + R->max.y * R->max.y) < Rad2);
   	else if (R->min.y > 0)  	/* R in upper right corner */
     		return ((R->min.x * R->min.x + R->min.y * R->min.y) < Rad2);
   	else 				/* R due East of circle */
     		return (R->min.x < Rad);
 	else				/* R on circle vertical centerline */
   		if (R->max.y < 0) 	/* R due South of circle */
     		return (ABS(R->max.y) < Rad);
   	else if (R->min.y > 0)  	/* R due North of circle */
     		return (R->min.y < Rad);
   	else 				/* R contains circle centerpoint */
     		return(TRUE);
} 	

bool CircleRectCD (double cx, double cy, double r, double min[2], double max[2])
{
	Box2 R;
	Point2 C;

	C.x = cx, C.y = cy;
	R.max.x = max[0], R.max.y = max[1]; 
	R.min.x = min[0], R.min.y = min[1]; 
	
	return Check_Intersect (&R, &C, r);	
}

int main(int argc, char** argv) {
   if (argc != 8)
       exit (1);
   double cx, cy, r;
   double min[2], max[2];
   
   cx = atof (argv[1]);
   cy = atof (argv[2]);
   r  = atof (argv[3]);

   min[0] = atof (argv[4]);
   min[1] = atof (argv[5]);
   max[0] = atof (argv[6]);
   max[1] = atof (argv[7]);
   
   printf ("%d\n", CircleRectCD (cx, cy, r, min, max));
}

