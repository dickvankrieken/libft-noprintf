/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/14 21:06:29 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/03/27 07:33:46 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H


# include <stdio.h> /* verwijder voor inleveren */
# include <stdarg.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_convert
{
	va_list	ap;
	int		printcounter;
	int		width;
	int		precision;
	bool		minus;
	bool		zero;
	char		type;
	char		c;
	char		*s;
	char		*p;
	int		d;
	int		i;
	unsigned int	u;
	unsigned int	x;
	unsigned int	X;
}	t_convert;

/* printcounter houdt bij hoe lang het te printen stukje tekst uiteindelijk wordt */

/* checkfunctions.c prototypes */
int	ft_checkflag(char *format, t_convert *conv_specs);
int	ft_checkprecision(char *format, t_convert *conv_specs);
int	ft_checkasterisk(char *format, t_convert *conv_specs);
int	ft_checkwidthdigit(char *format, t_convert *conv_specs);
int	ft_checktype(char *format, t_convert *conv_specs);

/* ft_printf.c prototypes */
int	ft_printf(const char*, ...);
int	init_convspecs(t_convert *conv_specs);
int	ft_putconvstring(char *string);
int	check_conversion(char *format, t_convert *conv_specs);
/* int	ft_checkspec(char *format, int i, t_convert *conv_specs, va_list ap);*/
int	isconvspecifier(char *format, t_convert *conv_specs);

/* put_functions.c prototypes */
void	ft_putconversion(t_convert *conv_specs);
void 	ft_putleftjustification(t_convert *conv_specs);
void 	ft_putjustification(t_convert *conv_specs);
void	ft_putchar_pf(char c, t_convert *conv_specs);

/* printspecs functions for development */
int	printspecs(t_convert conv_specs);

#endif
