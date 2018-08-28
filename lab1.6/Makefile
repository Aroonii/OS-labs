# the compiler: gcc for C program, define as g++ for C++
CC = gcc
# Remove command for with recursive and force flags
RM = rm -rf
# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall
# Shared Memory Flags
SHM_FLAGS = -lrt

newproc-posix: newproc-posix.c
	$(CC) $(CFLAGS) -o $@.o $<

fork-question-1: fork-question-1.c
	$(CC) $(CFLAGS) -o $@.o $<

fork-question-2: fork-question-2.c
	$(CC) $(CFLAGS) -o $@.o $<

shm-posix-consumer: shm-posix-consumer.c
	$(CC) $(CFLAGS) $(SHM_FLAGS) -o $@.o $<

shm-posix-producer: shm-posix-producer.c
	$(CC) $(CFLAGS) $(SHM_FLAGS) -o $@.o $<

unix_pipe: unix_pipe.c
	$(CC) $(CFLAGS) -o $@.o $<

simple-shell: simple-shell.c
	$(CC) $(CFLAGS) -o $@.o $<


clean:
	$(RM) *.o
