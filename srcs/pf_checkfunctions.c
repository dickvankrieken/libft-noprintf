/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_checkfunctions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/14 19:08:34 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/06/10 22:24:01 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../srcs/libft/libft.h"

int	pf_checkflag(char *format, t_convert *p)
{
	int	i;

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
		if (p->zero == 1)
			p->zero = 0;
	}
	return (i);
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
	char	*string;
	int		i;

	i = 0;
	while (ft_isdigit(format[i]))
		i++;
	if (i)
	{
		string = ft_substr(format, 0, i);
		p->width = ft_atoi(string);
		free(string);
	}
	return (i);
}

int	pf_checktype(char *format, t_convert *p)
{
	if (*format == 'd' || *format == 'i' || *format == 'u')
	{
		p->type = *format;
		return (1);
	}
	if (*format == 'x' || *format == 'X' || *format == 'c')
	{
		p->type = *format;
		return (1);
	}
	if (*format == 'p' || *format == 's' || *format == '%')
	{
		p->type = *format;
		return (1);
	}
	return (0);
}
