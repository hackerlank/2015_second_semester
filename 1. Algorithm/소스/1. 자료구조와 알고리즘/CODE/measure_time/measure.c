#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main( void )
{
   long    i = 60000000L;
   clock_t start, finish;
   double  duration;

   /* Measure the duration of an event. */
   printf("%i ������ �����ϴ� �ð���  ", i);
   start = clock();
   while( i-- ) 
      ;
   finish = clock();
   duration = (double)(finish - start) / CLOCKS_PER_SEC;
   printf("%f ���Դϴ�.\n", duration);
}
