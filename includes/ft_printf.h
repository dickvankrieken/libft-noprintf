/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/14 21:06:29 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/05/26 19:00:30 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h> /* verwijder voor inleveren */
# include <stdarg.h>
# include <stdbool.h>
# include "../srcs/libft/libft.h"

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
	unsigned long	p;
	int		d;
	int		i;
	unsigned int	u;
	unsigned int	x;
	unsigned int	X;
}	t_convert;

/* ../srcs/pf_checkfunctions.c prototypes */
int	pf_checkflag(char *format, t_convert *p);
int	pf_checkprecision(char *format, t_convert *p);
int	pf_checkasterisk(char *format, t_convert *p);
int	pf_checkwidthdigit(char *format, t_convert *p);
int	pf_checktype(char *format, t_convert *p);
/* ../srcs/ft_printf.c prototypes */
int	ft_printf(const char *format, ...);
int	pf_check_conversion(char *format, t_convert *p);
/* ../srcs/pf_ultohex.c prototypes */
char	*pf_ultohex(unsigned long n, int isupper);

/* ../srcs/ */
/* ../srcs/pf_putfunctions.c prototypes */
void	pf_putconversion(t_convert *p);
void	pf_putspaces(t_convert *p, int len);
void	pf_putzero(t_convert *p, int len);
void	pf_putc(t_convert *p);

/* ../srcs/puts */
/* ../srcs/puts/pf_puts.c prototypes */
void	pf_puts(t_convert *p);

/* ../srcs/putd */
/* ../srcs/putd/pf_putd.c prototypes */
void	pf_putd(t_convert *p);
void	pf_putd_precision(t_convert *p);
void	pf_putd_width_precision(t_convert *p);
/* ../srcs/putd/pf_putd_zero.c prototypes */
void	pf_putd_zero(t_convert *p);
/* ../srcs/putd/pf_putd_minus.c prototypes */
void	pf_putd_minus(t_convert *p);

/* ../srcs/putp */
/* ../srcs/putp/pf_putp.c prototypes */
void	pf_putp(t_convert *p);

/* ../srcs/putx/pf_putx.c */
void	pf_putx(t_convert *p);
void	pf_putx_precision(t_convert *p);
void	pf_putx_checkprecision(t_convert *p);

/* ../srcs/putu */
/* ../srcs/putu/pf_putu.c prototypes */
void	pf_putu(t_convert *p);
char	*ft_uitoa(unsigned int n);
int	pf_putu_precision(t_convert *p);
void	pf_putu_width(t_convert *p);
void	pf_putu_width_precision(t_convert *p);
void	pf_putu_minus(t_convert *p);
void	pf_putu_zero(t_convert *p);
void	pf_putu_zero_width(t_convert *p);

/* printspecs function for development */
int	printspecs(t_convert p);

#endif
