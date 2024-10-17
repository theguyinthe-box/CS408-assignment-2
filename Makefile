# CXX Make variable for compiler
CC=g++
# -std=c++11  C/C++ variant to use, e.g. C++ 2011
# -Wall       show the necessary warning files
# -g3         include information for symbolic debugger e.g. gdb 
CCFLAGS = -std=c++11 -Wall -g3 -c
CFLAGS = -g3 -c

# object files
OBJS = main.o log.o scheduler.o process.o

# Program name
PROGRAM = schedule

# The program depends upon its object files
$(PROGRAM) : $(OBJS)
	$(CC) -pthread -o $(PROGRAM) $(OBJS)

main.o : main.cpp
	$(CC) $(CCFLAGS) main.cpp

scheduler.o : scheduler.cpp scheduler.h
	$(CC) $(CCFLAGS) scheduler.cpp

process.o : process.cpp process.h
	$(CC) $(CCFLAGS) process.cpp

log.o : log.cpp log.h
	$(CC) $(CFLAGS) log.cpp

clean :
	rm -f *.o *~ $(PROGRAM)

