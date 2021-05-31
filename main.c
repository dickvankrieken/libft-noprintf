#include "includes/ft_printf.h"
#include "srcs/libft/libft.h"
#include <stdio.h>

int main()
{

	/* printf("\ntestx:\n"); */
	/* testx(); */
	/* printf("\ntestp:\n"); */
	/* testp(); */
	/* printf("\ntestd:\n"); */
	/* testd(); */
	/* printf("\ntestu:\n"); */
	/* testu(); */
//	int res;

//	model
//	res = ft_printf(">%..s<\n", ...);
//	printf("return waarde: %d\n", res);
//	res = printf(">%32s<\n", "abc");
//	printf("return waarde: %d\n", res);

	int main()
	{
		char *s1 = "Check %5.*d";
		if (ft_printf(s1, -5, 1234) != printf(s1, -5, 1234))
			printf("error?!\n");
		while (1)
		{}
	}

	ft_printf(" dit is een %%5.10d: %5.10d", 1234);


	printf(" dit is een %%5.10d: %5.10d", 1234);


}
