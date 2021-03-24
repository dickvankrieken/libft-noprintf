/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/14 21:08:31 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/03/24 16:26:44 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* temporary function only for testing purposes */
int	printspecs(t_convert conv_specs)
{
	printf("width: _%d_\n", conv_specs.width);
	printf("precision (.): _%d_\n", conv_specs.precision);
	printf("left-justified (-): _%d_\n", conv_specs.minus);
	printf("zero-padding (0): _%d_\n", conv_specs.zero);
	printf("conversion-type: _%c_\n", conv_specs.type);
	return (0);
}

int	init_convspecs(t_convert *conv_specs)
{
	conv_specs->width = 0;
	conv_specs->precision = -1; /* precision 0 is anders dan geen precision voor strings bijvoorbeeld */
	conv_specs->minus = 0;
	conv_specs->zero = 0;
	conv_specs->type = 'z';
	return (0);
}

/* voor iedere conversie type wordt er een individuele conversiefunctie die stuk voor stuk de conv_specs om gaan zetten naar de te printen string en deze functies geven een gealloceerde string terug. */
char	*ft_putconversions(t_convert *conv_specs)
{
	char *string;

	if (conv_specs->type == 'c')
		string = ft_conv_c(conv_specs);
	if (conv_specs->type == 's')
		string = ft_conv_s(conv_specs);
	if (conv_specs->type == 'p')
		string = ft_conv_p(conv_specs);
	if (conv_specs->type == 'd' || conv_specs->type == 'i')
		string = ft_conv_d(conv_specs);
	if (conv_specs->type == 'u')
		string = ft_conv_u(conv_specs);
	/* if x || of X */
	return (string);
}

/* deze functie wordt aangeroepen als er een procent teken gevonden is in de format string.
De functie gaat de conversie specificatie analyzeren, de gegevens in de t_convert struct zetten en ten slotte de conversie maken.
De functie returnt het aantal karakters van de format string dat verwerkt is, zodat de parse functie verder kan gaan met de format string controleren na de conversie specificatie. */

int	check_conversion(char *format, t_convert *conv_specs)
{
	int i;

	i = 0;
	while (ft_checkflag(&format[i], conv_specs))
		i++;
	if (ft_checkasterisk(&format[i], conv_specs))
		i++;
	/* check for digits for the width */
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
	return (i);
}


int	ft_parse(char *format, va_list ap)
{
	t_convert	conv_specs;
	char		*converted_argument;
	int		i;
	int		ret;

	init_convspecs(&conv_specs);
//	printspecs(conv_specs);
	i = 0;
	ret = 0;
	while (i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			i++;
			i += check_conversion(&format[i], &conv_specs);
			// string = ft_convtostring(conv_specs, ap); dit hoeft wellicht allemaal niet als de manier die ik hieronder probeer werkt.
			// ret += ft_putconverted(string);
			// free(string);
			ret += ft_putconvstring(ft_convtostring(conv_specs, ap));
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			i++;
			ret++;
		}
	}
 	/* printf("de conversion type: |%c| en i is nu: |%d|\n", conv_specs.type, i); */
//	printspecs(conv_specs);
	return (ret);
}

int	ft_printf(const char *format, ...)
 {
	va_list	ap;
	int		written_bytes;

	va_start(ap, format);
	written_bytes = ft_parse((char *)format, ap);
	va_end(ap);
	return (written_bytes);
}
