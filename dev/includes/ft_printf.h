/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/14 21:06:29 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/03/25 11:08:23 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
	char		*x;
	char		*X;
}	t_convert;

/* hou in je struct bij hoe lang het te printen stukje tekst uiteindelijk wordt */

int	ft_printf(const char*, ...);

int	ft_checkflag(char *format, t_convert *conv_specs);
int	ft_checkprecision(char *format, t_convert *conv_specs, va_list ap);
int	ft_checkasterisk(char *format, t_convert *conv_specs, va_list ap);
int	ft_checkwidthdigit(char *format, t_convert *conv_specs);
int	ft_checktype(char *format, t_convert *conv_specs);

int	init_convspecs(t_convert *conv_specs);
int	ft_putconvstring(char *string);

int	check_conversion(char *format, va_list ap, t_convert *conv_specs);
int	ft_spectostruct(char *format, t_convert *conv_specs, va_list ap);
/* int	ft_checkspec(char *format, int i, t_convert *conv_specs, va_list ap);*/
int	isconvspecifier(char *format, t_convert *conv_specs);
int	put_conversion(t_convert conv_specs);

#endif
