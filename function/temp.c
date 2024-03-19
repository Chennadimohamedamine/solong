#include "../so_long.h"

void print(char **s)
{
    int i = 0;
    while(s[i])
        printf("line : %s\n",s[i++]);
}