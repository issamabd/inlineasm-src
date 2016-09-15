/* 
*	shll.c
*
* Issam Abdallah, Information Engineer, Tunisia.
* Email: iabdallah@yandex.com
* Web site: issamabd.com
*/


#include <stdio.h>

int main(void)
{
 int a = 2;
 int res;

 __asm__ __volatile__( "shll\t$2, %1" : "=r" (res) : "r" (a) : "cc");

 printf("%d << 2 = %d \n", a, res);
 return 0;
}   
