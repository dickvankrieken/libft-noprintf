#include "../libft/libft.h"
#include "../includes/ft_printf.h"

void	ft_putconversion(t_convert *conv_specs)
{
	if (conv_specs->type == 'c')
		ft_putc_pf(conv_specs);
	if (conv_specs->type == 's')
		ft_puts_pf(conv_specs);
	/* if (conv_specs->type == 'p') */
	/* 	conv_specs->p = va_arg(conv_specs->ap, char *); */
	/* if (conv_specs->type == 'd') */
	/* 	conv_specs->d = va_arg(conv_specs->ap, int); */
	/* if (conv_specs->type == 'i') */
	/* 	conv_specs->i = va_arg(conv_specs->ap, int); */
	/* if (conv_specs->type == 'u') */
	/* 	conv_specs->u = va_arg(conv_specs->ap, unsigned int); */
	/* if (conv_specs->type == 'x') */
	/* 	conv_specs->u = va_arg(conv_specs->ap, unsigned int); */
	/* if (conv_specs->type == 'X') */
	/* 	conv_specs->u = va_arg(conv_specs->ap, unsigned int); */
}

void	ft_putc_pf(t_convert *conv_specs)
{
	write(1, &conv_specs->c, sizeof(char));
	conv_specs->printcounter++;
}

void ft_puts_precision(t_convert *conv_specs)
{

}
