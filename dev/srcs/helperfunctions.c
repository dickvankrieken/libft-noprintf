/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helperfunctions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/14 19:08:34 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/03/24 10:18:42 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h> /* dit is alleen voor de originele printf verwijder later */
#include "../includes/ft_printf.h"
#include "../libft/libft.h"



int	ft_checkflag(char *format, t_convert *conv_specs)
{
	int i;

	i = 0;
	if (format[i] == '0')
	{
		conv_specs->zero = 1;
		i++;
	}
	else if (format[i] == '-')
	{
		conv_specs->minus = 1;
		i++;
	}
	return (i);
}

int	ft_checkprecision(char *format, t_convert *conv_specs)
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
			conv_specs->precision = va_arg(conv_specs->ap, int);
			return (1);
		}
		else
		{
			while (ft_isdigit(format[i + j]))
				j++;
			if (j)
				conv_specs->precision = ft_atoi(ft_substr(format, i, j));
			return (1);
		}
	}
	return (0);
}

int	ft_checkasterisk(char *format, t_convert *conv_specs)
{
	if (*format == '*')
	{
		conv_specs->width = va_arg(conv_specs->ap, int);
		if (conv_specs->width < 0)
		{
			conv_specs->minus = 1;
			conv_specs->width *= -1;
		}
		return (1);
	}
	return (0);
}

int	ft_checkwidthdigit(char *format, t_convert *conv_specs)
{
	int	i;

	i = 0;
	while (ft_isdigit(format[i]))
		i++;
	if (i)
		conv_specs->width = ft_atoi(ft_substr(format, 0, i));
	return (i);
}

int	ft_checktype(char *format, t_convert *conv_specs)
{
	if (*format == 'd' || *format == 'i' || *format == 'u' || *format == 'x' || *format == 'p' || *format == 'X' || *format == 'c' || *format == 's' || *format == '%')
	{
		conv_specs->type = *format;
		return (1);
	}
	return (0);
}
