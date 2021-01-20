#include <stdio.h>

int main()
{
    FILE *f = fopen("/home/literal/interposelibc/interposelibc.conf", "r");
    if(!f) perror("fopen failed.");
    char *line = NULL;
    size_t linesize = 0;
    unsigned linenum = 1;
    while(getline(&line, &linesize, f) != -1)
    {
        printf("%d\t%s\n", linenum++, line);
    }
    return 0;
}