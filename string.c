/* 
*	string.c
*
* Issam Abdallah, Information Engineer, Tunisia.
* Email: iabdallah@yandex.com
* Web site: issamabd.com
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define	TAILLE 10
 
int main (void)
{
 char * str1 = (char*)
	malloc(TAILLE*sizeof(char));
 char * str2 = (char*)
	malloc(TAILLE*sizeof(char));

 if(!str1 || !str2)
	return EXIT_FAILURE;

 strcpy((char*)"foo", str1);
 strcpy((char*)"bar", str2);

 if(!strcmp(str1, str2))
	printf("The two strings \"%s\" and \"%s\" "\
	  "are equal.\n", str1, str2);
 else
	printf("The two strings \"%s\" and \"%s\" "\
	  "are not equal.\n", str1, str2);

 free (str1);
 free (str2);

 return EXIT_SUCCESS;
}
