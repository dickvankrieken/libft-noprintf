#include "includes/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int main()
{
	int a = -12345;
	int b = 2190;
	char c = 'e';
	char d = 'd';

	char *string = "hello world";
	char *pointer = string;
	char **ppointer = &pointer;

	ft_printf(">>>%p<<< en >>>%p<<<\n", pointer, ppointer);
	printf(">>>%p<<< en >>>%p<<<\n", pointer, ppointer);

	/* ft_printf("%s", "hello world"); */
}
