#include <stdio.h>
#include <stdlib.h>
#include "op.h"

long op(long a, long b, char znak)
{
	switch (znak)
	{
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '%': 
			  if (b == 0)
			  {
				  fprintf(stderr,"Error\n");
				  exit(EXIT_FAILURE);
			  }
			  else return a % b;
		case '&':
			 if (a>=0 && b>=0)
			 {
				 return a & b;
			 }
			 else
			 {
				 fprintf(stderr,"Error\n");
				 exit(EXIT_FAILURE);
			 }
		case '|': 
			 if (a>=0 && b>=0)
			 {
				 return a | b;
			 }
			 else
			 {
				 fprintf(stderr, "Error\n");
				 exit(EXIT_FAILURE);
			 }
		case '^': 
			 if (a>=0 && b>=0)
			 {
				 return a ^ b;
			 }
			 else
			 {
				 fprintf(stderr,"Error\n");
				 exit(EXIT_FAILURE);
			 }
		case '~': return ~a;
		default: fprintf(stderr,"Нет такой операции\n");
			 exit(EXIT_FAILURE);
	}
}
