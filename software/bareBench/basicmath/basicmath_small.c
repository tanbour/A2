#include <stdio.h>
#include "snipmath.h"
#include <math.h>
#include "../bareBench.h"

/* The printf's may be removed to isolate just the math calculations */

int main(void)
{
  double  a1 = 1.0, b1 = -10.5, c1 = 32.0, d1 = -30.0;
  double  a2 = 1.0, b2 = -4.5, c2 = 17.0, d2 = -30.0;
  double  a3 = 1.0, b3 = -3.5, c3 = 22.0, d3 = -31.0;
  double  a4 = 1.0, b4 = -13.7, c4 = 1.0, d4 = -35.0;
  double  x[3];
  double X;
  int     solutions;
  int i;
  unsigned long l = 0x3fed0169L;
  struct int_sqrt q;

  /* solve soem cubic functions */
  printf("********* CUBIC FUNCTIONS ***********\n\r");
  /* should get 3 solutions: 2, 6 & 2.5   */
  SolveCubic(a1, b1, c1, d1, &solutions, x);  
  printf("Solutions:");
  for(i=0;i<solutions;i++)
    printf(" %f",x[i]);
  printf("\n\r");
  /* should get 1 solution: 2.5           */
  SolveCubic(a2, b2, c2, d2, &solutions, x);  
  printf("Solutions:");
  for(i=0;i<solutions;i++)
    printf(" %f",x[i]);
  printf("\n\r");
  SolveCubic(a3, b3, c3, d3, &solutions, x);
  printf("Solutions:");
  for(i=0;i<solutions;i++)
    printf(" %f",x[i]);
  printf("\n\r");
  SolveCubic(a4, b4, c4, d4, &solutions, x);
  printf("Solutions:");
  for(i=0;i<solutions;i++)
    printf(" %f",x[i]);
  printf("\n\r");
  /* Now solve some random equations */
  for(a1=1;a1<10;a1++) {
    for(b1=10;b1>0;b1--) {
      for(c1=5;c1<15;c1+=0.5) {
	for(d1=-1;d1>-11;d1--) {
	  SolveCubic(a1, b1, c1, d1, &solutions, x);  
	  printf("Solutions:");
	  for(i=0;i<solutions;i++)
	    printf(" %f",x[i]);
	  printf("\n\r");
	}
      }
    }
    }
  
  printf("********* INTEGER SQR ROOTS ***********\n\r");
  /* perform some integer square roots */
  for (i = 0; i < 200; ++i)
    {
      usqrt(i, &q);
			// remainder differs on some machines
     // printf("sqrt(%3d) = %2d, remainder = %2d\n\r",
     printf("sqrt(%3d) = %2d\n\r",
	     i, q.sqrt);
    }
  usqrt(l, &q);
  //printf("\n\rsqrt(%lX) = %X, remainder = %X\n\r", l, q.sqrt, q.frac);
  printf("\n\rsqrt(%lX) = %X\n\r", l, q.sqrt);


  printf("********* ANGLE CONVERSION ***********\n\r");
  /* convert some rads to degrees */
  for (X = 0.0; X <= 360.0; X += 4.0)
    printf("%3.0f degrees = %.12f radians\n\r", X, deg2rad(X));
  printf("\n\r");
  for (X = 0.0; X <= (PI + 1e-6); X += (PI / 180) * 4)
    printf("%.12f radians = %3.0f degrees\n\r", X, rad2deg(X));
  
  return 0;
}
