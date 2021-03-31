#include "../includes/ft_printf.h"
#include <stdio.h>
/* temporary function only for testing purposes */

int	printspecs(t_convert p)
{
	printf("width: _%d_\n", p.width);
	printf("precision (.): _%d_\n", p.precision);
	printf("left-justified (-): _%d_\n", p.minus);
	printf("zero-padding (0): _%d_\n", p.zero);
	printf("conversion-type: _%c_\n", p.type);
	if (p.type == 'c')
	printf("%%c value: %c\n", p.c);
	if (p.type == 's')
	    printf("%%s value: %s\n", p.s);
	if (p.type == 'p')
		printf("%%p value: %p\n", p.p);
	if (p.type == 'd')
		printf("%%d value: %d\n", p.d);
	if (p.type == 'i')
		printf("%%i value: %i\n", p.i);
	if (p.type == 'u')
		printf("%%u value: %u\n", p.u);
	if (p.type == 'x')
		printf("%%x value: %x\n", p.x);
	if (p.type == 'X')
		printf("%%x value: %X\n", p.X);
	return (0);
}
