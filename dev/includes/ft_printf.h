/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/14 21:06:29 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/03/31 13:28:18 by dvan-kri      ########   odam.nl         */
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

/* printcounter keeps track of the number of bytes written */

/* ../srcs/checkfunctions.c prototypes */
int	pf_checkflag(char *format, t_convert *p);
int	pf_checkprecision(char *format, t_convert *p);
int	pf_checkasterisk(char *format, t_convert *p);
int	pf_checkwidthdigit(char *format, t_convert *p);
int	pf_checktype(char *format, t_convert *p);

/* ../srcs/ft_printf.c prototypes */
int	pf_printf(const char*, ...);
int	pf_init_convspecs(t_convert *p);
int	pf_putconvstring(char *string);
int	pf_check_conversion(char *format, t_convert *p);
int	pf_isconvspecifier(char *format, t_convert *p);

/* ../srcs/putfunctions.c prototypes */
void	pf_putconversion(t_convert *p);
void	pf_putspaces(int len);
void	pf_putzero(int len);
void	pf_putc(t_convert *p);
/* ../srcs/pf_puts.c prototypes */
void	pf_puts(t_convert *p);



/* printspecs function for development */
int	printspecs(t_convert p);

#endif
