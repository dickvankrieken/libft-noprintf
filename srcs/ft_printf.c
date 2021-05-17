/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/14 21:08:31 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/05/17 15:23:40 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../srcs/libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* zet p naar initiele waardes  */
int	pf_init_convspecs(t_convert *p)
{
	p->width = 0;
	p->precision = -1; /* precision 0 is anders dan geen precision voor strings bijvoorbeeld */
	p->minus = 0;
	p->zero = 0;
	p->type = 'z';
	return (0);
}

void	pf_argtostruct(t_convert *p)
{
	if (p->type == 'c')
		p->c = va_arg(p->ap, int);
	if (p->type == 's')
		p->s = va_arg(p->ap, char *);
	if (p->type == 'p')
		p->p = va_arg(p->ap, unsigned long);
	if (p->type == 'd')
		p->d = va_arg(p->ap, int);
	if (p->type == 'i')
		p->i = va_arg(p->ap, int);
	if (p->type == 'u')
		p->u = va_arg(p->ap, unsigned int);
	if (p->type == 'x')
		p->x = va_arg(p->ap, unsigned int);
	if (p->type == 'X')
		p->X = va_arg(p->ap, unsigned int);
	if (p->type == '%')
		p->c = '%';
}

/* check_conversion starts when % is found in format string.
it analyzes the conversion specificationf and stores relevant data in a t_convert struct.
It returns the amount of characters of the format string that have been processed. */
int	pf_check_conversion(char *format, t_convert *p)
{
	int i;

	i = 0;
	while (pf_checkflag(&format[i], p))
	{
		i++;
	}
 	if (pf_checkasterisk(&format[i], p))
	{
		i++;
	}
	if (pf_checkwidthdigit(&format[i], p))
	{
		i += ft_intcountchars(p->width);
	}
	if (pf_checkprecision(&format[i], p))
	{
		if (p->precision)
			i += ft_intcountchars(p->precision);
		else
			i++;
	}
	while (!pf_checktype(&format[i], p))
		i++;
	if (pf_checktype(&format[i], p))
		i++;
	pf_argtostruct(p);
	return (i);
}

void	pf_parse(char *format, t_convert *p)
{
	int		i;

	pf_init_convspecs(p);
	i = 0;
	p->count = 0;
	while (i < (int)ft_strlen(format))
	{
		if (format[i] == '%')
		{
			i++;
			i += pf_check_conversion(&format[i], p);
			/* printspecs(p); */
			pf_putconversion(p);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			p->count++;
			i++;
		}
		pf_init_convspecs(p);
	}
}

int	ft_printf(const char *format, ...)
{
	t_convert	p;

	va_start(p.ap, format);
	pf_parse((char *)format, &p);
	va_end(p.ap);
	return (p.count);
}