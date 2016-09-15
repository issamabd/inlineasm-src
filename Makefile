CFLAGS = -O2 -fomit-frame-pointer -W -Wall
objects = movl.o addition1.o addition2.o appel_sys.o \
	  division.o multiplication.o shll.o puissance.o 
	  
all: movl addition1 addition2 appel_sys \
	division multiplication shll \
	max string puissance 

movl: movl.o
addition1: addition1.o
addition2: addition2.o 
appel_sys: appel_sys.o
division: division.o 
multiplication: multiplication.o 
puissance: puissance.o
shll: shll.o
max: max.o
string: string.o

max.o: max.c max.h
	cc -c $(CFLAGS) max.c -o max.o 

string.o: string.c string.h
	cc -c -fno-builtin $(CFLAGS) string.c -o string.o 

$(objects): %.o : %.c
	cc -c $(CFLAGS) $< -o $@ 

clean:
	rm -rfv $(objects) max.o string.o *~

