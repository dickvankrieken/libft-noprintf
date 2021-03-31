#include "../includes/ft_printf.h"

void	pf_puts(t_convert *p)
{
	int i;
	int len;

	len = ft_strlen(p->s);
	i = 0;
	if (p->s)
	{
		if (p->width)
		{
			if (p->minus)
			{
				if (p->precision > -1)
				{
					write(1, p->s, p->precision);
					pf_putspaces(p->width - p->precision);
				}
				else
				{
					write(1, p->s, ft_strlen(p->s));
					pf_putspaces(p->width - ft_strlen(p->s));
				}
			}
			else if (p->zero)
			{
				if (p->precision > -1)
				{
					pf_putzero(p->width - p->precision);
					write(1, p->s, p->precision);
				}
				else
				{
					pf_putzero(p->width - ft_strlen(p->s));
					write(1, p->s, ft_strlen(p->s));
				}
			}
			else
			{
				if (p->precision)
				{
					write(1, p->s, p->precision);
					pf_putspaces(p->width - p->precision);
				}
				pf_putspaces(p->width - ft_strlen(p->s));
				write(1, p->s, ft_strlen(p->s));
			}
			p->printcounter += p->width;
		}
		else
		{
			if (p->precision)
			{
				write(1, p->s, p->precision);
				if (p->precision < ft_strlen(p->s))
					p->printcounter += p->precision;
				else
					p->printcounter += ft_strlen(p->s);
			}
			else
				write(1, p->s, ft_strlen(p->s));
		}
	}
}


	/******************************************************************************/
	/* 		/\* if there is a width, first check if there is precision, *\/		  */
	/* 		if (p->precision > -1)												  */
	/* 		{																	  */
	/* 			if (p->minus)													  */
	/* 			{																  */
	/* 				while (i < p->precision && i < len)							  */
	/* 				{															  */
	/* 					write(1, p->s, 1);										  */
	/* 					p->s++;													  */
	/* 					p->printcounter++;										  */
	/* 					i++;													  */
	/* 				}															  */
	/* 				write(1, p->s, ft_strlen(p->s));							  */
	/* 																			  */
	/* 			}																  */
	/* 		}																	  */
	/* 																			  */
	/* 		write(1, p->s, ft_strlen(p->s));									  */
	/* 																			  */
	/* 	}																		  */
	/* 	else																	  */
	/* 	{																		  */
	/* 		write(1, p->s, ft_strlen(p->s));									  */
	/* 		p->printcounter += ft_strlen(p->s);									  */
	/* 	}																		  */
	/* }																		  */
	/******************************************************************************/
