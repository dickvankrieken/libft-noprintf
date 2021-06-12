#include "includes/ft_printf.h"
#include "srcs/libft/libft.h"
#include <stdio.h>

int main()
{
//	model
//	res = ft_printf(">%..s<\n", ...);
//	printf("return waarde: %d\n", res);
//	res = printf(">%32s<\n", "abc");
//	printf("return waarde: %d\n", res);

	int res;
	res = printf("%.d", 0);
//	res = ft_printf("%%p::[%.5d]\n", -8473);
	printf("return waarde: %d\n", res);

	res = ft_printf("%.d", 0);
//	res = printf("%%p::[%.5d]\n", -8473);
	printf("return waarde: %d\n", res);

// edge case proberen: ft_printf("%.-0x", 0);
}
