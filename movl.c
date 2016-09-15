/* 
*	movl.c
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

 __asm__("movl\t%1, %0"

	 : "=&r" (a) /* or "=&r" (a) */
	 : "r" (b)
	 : /* modifications list */
	);

 printf("a = b = %d \n", a);
 return 0;
}    
