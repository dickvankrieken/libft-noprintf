/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_checkfunctions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/14 19:08:34 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/04/13 11:00:00 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h> /* dit is alleen voor de originele printf verwijder later */
#include "../includes/ft_printf.h"
#include "../srcs/libft/libft.h"

int	pf_checkflag(char *format, t_convert *p)
{
	int i;

	i = 0;
	if (format[i] == '0')
	{
		p->zero = 1;
		i++;
	}
	else if (format[i] == '-')
	{
		p->minus = 1;
		i++;
		if (p->zero == 1) /* bij alle specifiers is het zo dat als er zowel een 0 als een min is, de 0 wordt genegeerd en de - wordt toegepast (links uitgelijnd heb je geen ruimte meer voor nullen) */
			p->zero = 0;
	}
	return (i);
}

int	pf_checkprecision(char *format, t_convert *p)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (format[i] == '.')
	{
		i++;
		if (format[i] == '*')
		{
			p->precision = va_arg(p->ap, int);
			return (1);
		}
		else
		{
			while (ft_isdigit(format[i + j]))
				j++;
			if (j)
				p->precision = ft_atoi(ft_substr(format, i, j));
			return (1);
		}
	}
	return (0);
}

int	pf_checkasterisk(char *format, t_convert *p)
{
	if (*format == '*')
	{
		p->width = va_arg(p->ap, int);
		if (p->width < 0)
		{
			p->minus = 1;
			p->width *= -1;
		}
		return (1);
	}
	return (0);
}

int	pf_checkwidthdigit(char *format, t_convert *p)
{
	int	i;

	i = 0;
	while (ft_isdigit(format[i]))
		i++;
	if (i)
		p->width = ft_atoi(ft_substr(format, 0, i));
	return (i);
}

int	pf_checktype(char *format, t_convert *p)
{
	if (*format == 'd' || *format == 'i' || *format == 'u' || *format == 'x' || *format == 'p' || *format == 'X' || *format == 'c' || *format == 's' || *format == '%')
	{
		p->type = *format;
		return (1);
	}
	return (0);
}
