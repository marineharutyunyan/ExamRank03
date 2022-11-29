#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 1
# endif

char *get_next_line(int fd);
#endif