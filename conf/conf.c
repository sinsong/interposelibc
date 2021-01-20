#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "conf.h"

struct interpose_conf conf;

/* come from openssh readconf.c */
#define WHITESPACE " \t\r\n"
#define QUOTE "\""

typedef enum{
    oBadOption,
    oAllFail,
} OpCodes;

struct{
    const char *name;
    OpCodes opcode;
} keywords[] = {
    {"allfail", oAllFail},
};

void init_conf()
{
    conf.all_fail = 0;
}

static char * strdelim(char **s, int split_equals)
{
    char *old;
    int wspace = 0;

    if(*s == NULL)
        return NULL;
    
    old = *s;

    *s = strpbrk(*s, split_equals ? WHITESPACE QUOTE "=" : WHITESPACE QUOTE);
    if(*s == NULL)
        return (old);

    if(*s[0] == '\"')
    {
        memmove(*s, *s + 1, strlen(*s)); // move nul too
        // find matching quote
        if((*s = strpbrk(*s, QUOTE)) == NULL)
        {
            return (NULL); // no matching quote
        }
        else
        {
             *s[0] = '\0';
             *s += strspn(*s + 1, WHITESPACE) + 1;
             return (old);   
        }
    }

    // allow only one '=' to be skipped
    if(split_equals && *s[0] == '=')
        wspace = 1;
    *s[0] = '\0';

    // skip any extra whitespace after first token
    *s += strspn(*s + 1, WHITESPACE) + 1;
    if(split_equals && *s[0] == '=' && !wspace)
        *s += strspn(*s + 1, WHITESPACE) + 1;

    return (old);
}

void lowercase(char *s)
{
    for(; *s; s++)
        *s = tolower((u_char)*s);
}

int parse_token(char* cp, unsigned linenum)
{
    int i;

    for(i = 0; keywords[i].name; ++i)
        if(strcmp(cp, keywords[i].name) == 0)
            return keywords[i].opcode;

    return oBadOption;
}

int parse_conf_line(char *line, size_t linesize, unsigned linenum)
{
    char *s, **charptr, *keyword, *arg, *arg2;
    size_t len;
    int opcode;

    // Strip trailing whitespace
    if((len = strlen(line)) == 0)
        return 0; // empty line
    for(len--; len>0; len--)
    {
        if(strchr(WHITESPACE "\f", line[len]) == NULL)
            break;
        line[len] = '\0';
    }

    s = line;
    if((keyword = strdelim(&s, 1)) == NULL)
        return 0;
    if(*keyword == '\0')
        keyword = strdelim(&s, 1);
    if(keyword == NULL || !*keyword || *keyword == '\n' || *keyword == '#')
        return 0;
    
    lowercase(keyword);

    //printf("keyword: %s\n", keyword);
    opcode = parse_token(keyword, linenum);

    switch(opcode)
    {
    case oBadOption:
        return -1;
    case oAllFail:
        conf.all_fail = 1;
        return 0;
    }
}

void parse_conf(FILE* f)
{
    char *line = NULL;
    size_t linesize = 0;
    unsigned linenum = 1;
    int bad_options = 0;
    while(getline(&line, &linesize, f) != -1)
    {
        if(parse_conf_line(line, linesize, linenum++) != 0)
            ++bad_options;
    }
    free(line);

    if (bad_options > 0)
        fprintf(stderr, "[interposelibc]: %d bad configuration options\n", bad_options);
}

