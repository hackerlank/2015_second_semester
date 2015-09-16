#include <stdio.h>

//
//
//
int fib(int i)
{
   if(n==0)
	  return 0;
   else if(i==1)
	  return 1;
   else
	  return fib(i-1)+fib(i-2);
}

//
//
//
int fibindex(int i)
{

}

//
//
//
search_fib(int x[], int z)
{
	int a, i, p, t, done;
	a = fibindex(n+1);
	i = fib(a-1)-1;
	p = fib(a-2);
	q = fib(a-3);
	done = FALSE;
	while((i>=0) && (!done)) {
		switch(compare(z, x[i])) {
		case '<': if(q==0) i=0;
			else {
				i = i-q; t=p;
				p = q; q=t-q; }
			break;
		case '>': if(p==1) i=0;
			else {
				i = i+q; p=p-q;
				q=q-p;
			}
				break;
		case '=':
			done = TRUE;
			return;
		}
	}
		if( i< 0) return -1;
}