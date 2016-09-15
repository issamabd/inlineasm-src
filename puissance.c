/* 
*	puissance.c
*
* Issam Abdallah, Information Engineer, Tunisia.
* Email: iabdallah@yandex.com
* Web site: issamabd.com
*/


#include <stdio.h> 

int main()
{

 int x = 10;
 int e=3;
 int result;

 __asm__ __volatile(
	 "movl $10, %%ebx\t\n"
	 "1:\t\n"
	 "mul %%ebx\n"
	 "loop 1b"

	 : "=&a" (result)
	 : "0" (x), "c" (e-1)
	 : "ebx");

 printf("%d^%d = %d\n", x,e, result);

 return 0;
}

