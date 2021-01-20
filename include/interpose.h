#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "conf.h"

#define INTERPOSE(name) (*interpose_##name)
#define INTERPOSE_NAME(name) interpose_##name

#define INTERPOSE_ALL_FAIL (conf.all_fail != 0)

extern pid_t INTERPOSE(fork)(void);
extern int	 INTERPOSE(execve)(const char *path, char * const *args, char * const *envv);
