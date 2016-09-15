/* 
*	appel_sys.c
*
* Issam Abdallah, Information Engineer, Tunisia.
* Email: iabdallah@yandex.com
* Web site: issamabd.com
*/


#include <asm/unistd.h> 	/* __NR_write */
#include <unistd.h>		/* STDOUT_FILENO */
#include <string.h>		/* strlen() */

#define STDOUT STDOUT_FILENO

int main(void)
{
 char msg[] = "hello!\n";
 int res;

 __asm__ __volatile__(
	"int  \t$0x80"

	:"=&a" (res)
	:"0" (__NR_write), "b" (STDOUT), 
	 "c" (msg), "d" (strlen(msg)) );

 return 0;
}

