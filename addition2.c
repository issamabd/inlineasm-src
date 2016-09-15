/* 
*	addition2.c
*
* Issam Abdallah, Information Engineer, Tunisia.
* Email: iabdallah@yandex.com
* Web site: issamabd.com
*/

#include <stdio.h>

int main(void)
{
 int a = 10;	
 int b = 3;
 int res;	
 
 __asm__ __volatile__(
	"movl \t%1, %%eax\n\t"
	"addl \t%2, %%eax\n\t"	
	"subl \t%1, %1" 

	 : "=&a" (res)
	 : "r" (a), "r" (b));

 printf("%d + %d = %d \n", a, b, res);
 return 0;
} 
