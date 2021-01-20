#include <dlfcn.h>
#include <stdio.h>
#include "interpose.h"

#define RTLD_NEXT ((void *) -1l)
#define INTERPOSE_INIT(name) INTERPOSE_NAME(name) = dlsym(RTLD_NEXT, #name)

__attribute__((constructor))
void interposelibc_init()
{
    fprintf(stderr, "[interposelibc]: init\n");
    INTERPOSE_INIT(fork);
    INTERPOSE_INIT(execve);

    FILE *f = read_config_file();
    init_conf();
    parse_conf(f);
    fclose(f);
}