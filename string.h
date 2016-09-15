#ifndef MY_STRING_H
#define MY_STRING_H

static inline void 
strcpy(char * src, char * dest)
{

 int S, D, A;

 __asm__ __volatile__ ( 
	"cld\n"			/* ESI++, EDI++    */
	"1:\tlodsb\n\t" 	/* MOVB DS:ESI, AL */
	"stosb\n\t" 		/* MOVB AL, ES:EDI */
	"testb\t%%al,%%al\n\t"  /* ZF=1 if AL == 0 */
	"jne\t1b" 		/* JMP if ZF == 0  */

	: "=&S" (S),"=&D" (D), "=&a" (A) 
	: "0" (src),"1" (dest), "2" (0)
	: "memory");
 
 return;
}

static inline int 
strcmp(const char * str1,const char * str2)
{
 int S, D, __res;

 __asm__ __volatile__(
	"cld\n"		 	/* ESI++, EDI++   */
	"1:\tlodsb\n\t"	 	/* MOV DS:ESI, AL */
	"scasb\n\t"	     	/* SUB ES:ESI, AL */
	"jne \t2f\n\t"	    	/* JMP if ZF == 0 (ES:EDI != AL) */
	"testb \t%%al,%%al\n\t" /* ZF=1 if AL == 0 */
	"jne \t1b\n\t"	    	/* JMP if ZF == 0 */
	"xorl \t%%eax,%%eax\n\t"/* (str1 == str2) => __res = 0 */
	"jmp \t3f\n"	      	/* we finish! */
	"2:\tmovl $1,%%eax\n\t"
	"jl \t3f\n\t"	     	/* (str1 != str2) et (str1[i] > str2[i]) => __res = 1 */
	"negl\t%%eax\n"         /* (str1 != str2) et (str1[i] < str2[i]) => __res = -1 */
	"3:"

	:"=&D" (D), "=&S" (S),"=&a" (__res)
	:"0" (str1),"1" (str2), "2" (0)
	:"memory");

 return __res;
}
 
#endif
 
