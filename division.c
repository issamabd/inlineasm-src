/* 
*	division.c
*
* Issam Abdallah, Information Engineer, Tunisia.
* Email: iabdallah@yandex.com
* Web site: issamabd.com
*/


#include <stdio.h>

int main(void)
{
 int x = 10;	/* EAX */
 int divs = 3;
 int quot;	/* EAX */  
 int reste;	/* EDX */

 __asm__ __volatile__(
	"subl \t%%edx, %%edx\n\t"
	"movl \t%3, %%ebx\n\t"	
	"idivl \t%%ebx"
 
	 : "=&a" (quot), "=&d" (reste)
	 : "0" (x), "r" (divs)
	 : "ebx");

 printf("%d / %d = %d \n", x, divs, quot);
 printf("%d %% %d = %d \n", x, divs, reste);
 return 0;
}    
