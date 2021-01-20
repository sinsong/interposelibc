#include <stdio.h>

// #define CONF_FILENAME "/etc/interposelibc.conf"
#define CONF_FILENAME "/home/literal/interposelibc/interposelibc.conf"

struct interpose_conf{
    int all_fail;
};

extern struct interpose_conf conf;

void init_conf();
FILE *read_config_file();
void parse_conf(FILE* f);