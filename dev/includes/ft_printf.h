/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/14 21:06:29 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/04/23 09:51:08 by dvan-kri      ########   odam.nl         */
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
	va_list		ap;
	int		count;
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
	int		printcounter;
}	t_convert;

/* printcounter keeps track of the number of bytes written */

/* ../srcs/checkfunctions.c prototypes */
int	pf_checkflag(char *format, t_convert *p);
int	pf_checkprecision(char *format, t_convert *p);
int	pf_checkasterisk(char *format, t_convert *p);
int	pf_checkwidthdigit(char *format, t_convert *p);
int	pf_checktype(char *format, t_convert *p);

/* ../srcs/ft_printf.c prototypes */
int	ft_printf(const char*, ...);
int	pf_init_convspecs(t_convert *p);
int	pf_putconvstring(char *string);
int	pf_check_conversion(char *format, t_convert *p);
int	pf_isconvspecifier(char *format, t_convert *p);

/* ../srcs/putfunctions.c prototypes */
void	pf_putconversion(t_convert *p);
void	pf_putspaces(int len);
void	pf_putzero(int len);
void	pf_putc(t_convert *p);
/* ../srcs/putfunctions/puts prototypes */
void	pf_puts(t_convert *p);
/* ../srcs/putfunctions/puts/pf_puts_width.c prototypes */
void	pf_puts_width(t_convert *p);
void	pf_puts_width_minus_checkprecision(t_convert *p);
void	pf_puts_minus_with_precision(t_convert *p);
void	pf_puts_minus_noprecision(t_convert *p);
void	pf_puts_width_checkzero(t_convert *p);
/* ../srcs/putfunctions/putd prototypes */
/* ../srcs/putfunctions/putd/pf_putd.c prototypes */
void	pf_putd(t_convert *p);
int	pf_putd_precision(t_convert *p);
void	pf_putd_width_precision(t_convert *p);
void	pf_putd_zero(t_convert *p);
void	pf_putd_zero_width(t_convert *p);
void	pf_putd_zero_width_precision(t_convert *p);
void	pf_putd_zero_precision(t_convert *p);
int	pf_putd_precision(t_convert *p);
void	pf_putd_minus(t_convert *p);
void	pf_putd_minus_width(t_convert *p);
void	pf_putd_minus_width_precision(t_convert *p);
void	pf_putd_minus_precision(t_convert *p);
/* ../srcs/putfunctions/putp prototypes */
/* ../srcs/putfunctions/putp/pf_putp.c prototypes */
void	pf_putp(t_convert *p);
/* ../srcs/putfunctions/putp/pf_ultohex.c prototypes */
char	*pf_ultohex(int n);

/* printspecs function for development */
int	printspecs(t_convert p);

#endif
