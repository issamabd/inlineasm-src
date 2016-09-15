/* 
*	addition1.c
*
* Issam Abdallah, Information Engineer, Tunisia.
* Email: iabdallah@yandex.com
* Web site: issamabd.com
*/

#include <stdio.h>

int main(void)
{
 int a = 10;
 int b = 5;
 int res;

 __asm__ __volatile__(
	"addl\t%2, %1\n\t" 
	"movl\t%1, %0"

	 : "=r" (res) 
	 : "r" (a), "r"(b)
	 : /* modifications list*/
	);

 printf("%d + %d = %d \n", a, b, res);
 return 0;
}   
