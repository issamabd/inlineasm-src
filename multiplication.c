/* 
*	multiplication.c
*
* Issam Abdallah, Information Engineer, Tunisia.
* Email: iabdallah@yandex.com
* Web site: issamabd.com
*/


#include <stdio.h>

int main(void)
{
 int x = 10;	/* EAX */
 int mult = 3;
 int res;	/* EAX */
 
 __asm__ __volatile__(
	"movl \t%2, %%ebx\n\t"	
	"imul \t%%ebx" 

	 : "=&a" (res)		/* '&' is not mandatory but it's recommended */
	 : "0" (x), "r" (mult)
	 : "ebx");

 printf("%d * %d = %d \n", x, mult, res);
 return 0;
}     
