#include "includes/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int main()
{
    int a = 100;
    char c = 'e';
    char d = 'd';

    char *string = "hello world";
    char *pointer = string;
    char **ppointer = &pointer;

    ft_printf(">>>%-2d<<<\n", a);
    printf(">>>%-22.20d<<<\n", a);
}
