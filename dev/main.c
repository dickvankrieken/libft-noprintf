#include "includes/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>


static void testd()
{

	int i = 2345;
	int i2 = 2345678;
	int i3 = 234567890;

	   printf("printf    >>%10.3d<<\n", i);
	ft_printf("ft_printf >>%10.3d<<\n", i);
	   printf("printf    >>%10.3d<<\n", i2);
	ft_printf("ft_printf >>%10.3d<<\n", i2);
	   printf("printf    >>%10.3d<<\n", i3);
	ft_printf("ft_printf >>%10.3d<<\n", i3);
}

static void testx()
{
	int tohex = 190607;
	int tohex2 = 121990607;

	   printf("printf    >>%3.3x<<< en >>>%.10x<<<\n", tohex, tohex2);
	ft_printf("ft_printf >>%3.3x<<< en >>>%.10x<<<\n", tohex, tohex2);
	   printf("printf    >>%3.3x<<< en >>>%.10x<<<\n", tohex, tohex2);
	ft_printf("ft_printf >>%3.3x<<< en >>>%.10x<<<\n", tohex, tohex2);
}

static void testp()
{
	char c = 'e';
	char *helloworld = "hello world";
	char *pointer = helloworld;
	char *ppointer = &c;

	ft_printf(">>>%13p<<< en >>>%3p<<<\n", pointer, ppointer);
	printf(">>>%13p<<< en >>>%3p<<<\n", pointer, ppointer);
}

static void testu()
{
	unsigned int uint1 = 12345;
	unsigned int uint2 = -1;
	ft_printf(">>>%u<<< en >>>%u<<<\n", uint1, uint2);
	printf(">>>%u<<< en >>>%u<<<\n", uint1, uint2);
}


int main()
{

	/* printf("\ntestx:\n"); */
	/* testx(); */
	/* printf("\ntestp:\n"); */
	/* testp(); */
	/* printf("\ntestd:\n"); */
	/* testd(); */
	printf("\ntestu:\n");
	testu();

}
