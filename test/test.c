#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t p = fork();
    
    switch(p)
    {
    case -1:
        perror("fork failed");
        break;
    case 0:
        printf("child\n");
        break;
    default:
        printf("parents - child: %d\n", p);
        break;
    }

    return 0;
}