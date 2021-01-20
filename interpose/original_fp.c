#include "interpose.h"

pid_t INTERPOSE(fork)(void);
int	  INTERPOSE(execve)(const char *path, char * const *args, char * const *envv);