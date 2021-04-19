#include "includes/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int main()
{
	int a = -12345;
	char c = 'e';
	char d = 'd';

	char *string = "hello world";
	char *pointer = string;
	char **ppointer = &pointer;

	ft_printf(">>>%-.20d<<<\n", a);
	printf(">>>%-.20d<<<\n", a);
	/* ft_printf("%s", "hello world"); */
}
