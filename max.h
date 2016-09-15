#ifndef MAX_H
#define MAX_H

#define max(a,b)			\
({					\
 int __res;				\
 __asm__ __volatile__(			\
	"cmpl \t%1, %2\n\t" 		\
	"jge \t1f\n\t" 			\
	"movl \t%1, %0\n\t" 		\
	"jmp \t2f\n"			\
	"1:\t movl %2, %0\n" 		\
	"2:" 				\
					\
	: "=r" (__res) 			\
	:"r" ((int)a),			\
	 "r" ((int)b));			\
 __res;					\
}) 

#endif

