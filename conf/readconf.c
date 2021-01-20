#include <stdio.h>
#include "conf.h"

FILE *read_config_file()
{
    FILE *f = fopen(CONF_FILENAME, "r");
    return f;
}