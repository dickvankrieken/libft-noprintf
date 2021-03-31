/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/14 21:08:31 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/03/29 13:07:39 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* geef de conv_specs naar initiele waardes  */
int	init_convspecs(t_convert *conv_specs)
{
	conv_specs->width = 0;
	conv_specs->precision = -1; /* precision 0 is anders dan geen precision voor strings bijvoorbeeld */
	conv_specs->minus = 0;
	conv_specs->zero = 0;
	conv_specs->type = 'z';
	return (0);
}


void	ft_argtostruct(t_convert *conv_specs)
{
	if (conv_specs->type == 'c')
		conv_specs->c = va_arg(conv_specs->ap, int);
	if (conv_specs->type == 's')
		conv_specs->s = va_arg(conv_specs->ap, char *);
	if (conv_specs->type == 'p')
		conv_specs->p = va_arg(conv_specs->ap, char *);
	if (conv_specs->type == 'd')
		conv_specs->d = va_arg(conv_specs->ap, int);
	if (conv_specs->type == 'i')
		conv_specs->i = va_arg(conv_specs->ap, int);
	if (conv_specs->type == 'u')
		conv_specs->u = va_arg(conv_specs->ap, unsigned int);
	if (conv_specs->type == 'x')
		conv_specs->u = va_arg(conv_specs->ap, unsigned int);
	if (conv_specs->type == 'X')
		conv_specs->u = va_arg(conv_specs->ap, unsigned int);
}

/* check_conversion starts when % is found in format string.
it analyzes the conversion specificationf and stores relevant data in a t_convert struct.
It returns the amount of characters of the format string that have been processed. */
int	check_conversion(char *format, t_convert *conv_specs)
{
	int i;

	i = 0;
	while (ft_checkflag(&format[i], conv_specs))
		i++;
 	if (ft_checkasterisk(&format[i], conv_specs))
		i++;
	if (ft_checkwidthdigit(&format[i], conv_specs))
		i += ft_strlen(ft_itoa(conv_specs->width));
	if (ft_checkprecision(&format[i], conv_specs))
	{
		if (conv_specs->precision)
			i += ft_strlen(ft_itoa(conv_specs->precision));
		else
			i++;
	}
	while (!ft_checktype(&format[i], conv_specs))
		i++;
	if (ft_checktype(&format[i], conv_specs))
		i++;
	ft_argtostruct(conv_specs);
	return (i);
}

void	ft_parse(char *format, t_convert conv_specs)
{
	char		*converted_argument;
	/* no extra local counter because everything is done in struct variable printcounter? */
	int		i;

	init_convspecs(&conv_specs);
	i = 0;
	while (i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			i++;
			i += check_conversion(&format[i], &conv_specs);
			ft_putconversion(&conv_specs);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			i++;
		}
	}
	// printspecs(conv_specs);
//	return (i);
}

int	ft_printf(const char *format, ...)
 {
	t_convert	conv_specs;
	int		written_bytes;

	va_start(conv_specs.ap, format);
	ft_parse((char *)format, conv_specs);
	va_end(conv_specs.ap);
	return (conv_specs.printcounter);
}
