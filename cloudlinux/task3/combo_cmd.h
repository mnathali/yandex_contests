#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int     char_count(const char *str, char* sub_str);
char    **split_str(const char *str, char *delim);
int     multi_free(char **set_of_strings);
int     all_free(char ***cmds, int size);


