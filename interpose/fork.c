#include "interpose.h"

pid_t fork(void)
{
    if(INTERPOSE_ALL_FAIL)
    {
        errno = ENOMEM;
        return -1;
    }

    fprintf(stderr, "[interposelibc]: fork()\n");
    return INTERPOSE(fork)();
}