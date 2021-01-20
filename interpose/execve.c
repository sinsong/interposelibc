#include "interpose.h"

int	execve(const char *path, char * const *args, char * const *envv)
{
    if(INTERPOSE_ALL_FAIL)
    {
        errno = ENOMEM;
        return -1;
    }

    fprintf(stderr, "[interposelibc]: execve()\n");
    return INTERPOSE(execve)(path, args, envv);
}