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

	ft_printf(">>>%x<<< en >>>%x<<<\n", tohex, tohex2);
	printf(">>>%x<<< en >>>%x<<<\n", tohex, tohex2);

}
