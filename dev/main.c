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
	char *ppointer = &c;

	int tohex = 190607;
	int tohex2 = 121990607;

	ft_printf(">>>%13p<<< en >>>%3p<<<\n", pointer, ppointer);
	printf(">>>%13p<<< en >>>%3p<<<\n", pointer, ppointer);

	ft_printf(">>>%13.10x<<< en >>>%3x<<<\n", tohex, tohex2);
	printf(">>>%9.10x<<< en >>>%3x<<<\n", tohex, tohex2);

}
