#include "../includes/ft_printf.h"
#include <stdio.h>
/* temporary function only for testing purposes */

int	printspecs(t_convert conv_specs)
{
	printf("width: _%d_\n", conv_specs.width);
	printf("precision (.): _%d_\n", conv_specs.precision);
	printf("left-justified (-): _%d_\n", conv_specs.minus);
	printf("zero-padding (0): _%d_\n", conv_specs.zero);
	printf("conversion-type: _%c_\n", conv_specs.type);
	if (conv_specs.type == 'c')
	printf("%%c value: %c\n", conv_specs.c);
	if (conv_specs.type == 's')
	    printf("%%s value: %s", conv_specs.s);
	if (conv_specs.type == 'p')
		printf("%%p value: %p", conv_specs.p);
	if (conv_specs.type == 'd')
		printf("%%d value: %d", conv_specs.d);
	if (conv_specs.type == 'i')
		printf("%%i value: %i", conv_specs.i);
	if (conv_specs.type == 'u')
		printf("%%u value: %u", conv_specs.u);
	if (conv_specs.type == 'x')
		printf("%%x value: %x", conv_specs.x);
	if (conv_specs.type == 'X')
		printf("%%x value: %X", conv_specs.X);
	return (0);
}
