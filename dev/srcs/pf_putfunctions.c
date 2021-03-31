#include "../libft/libft.h"
#include "../includes/ft_printf.h"

void	pf_putconversion(t_convert *p)
{
	if (p->type == 'c')
		pf_putc(p);
	if (p->type == 's')
		pf_puts(p);
	/* if (p->type == 'p') */
	/* 	p->p = va_arg(p->ap, char *); */
	/* if (p->type == 'd') */
	/* 	p->d = va_arg(p->ap, int); */
	/* if (p->type == 'i') */
	/* 	p->i = va_arg(p->ap, int); */
	/* if (p->type == 'u') */
	/* 	p->u = va_arg(p->ap, unsigned int); */
	/* if (p->type == 'x') */
	/* 	p->u = va_arg(p->ap, unsigned int); */
	/* if (p->type == 'X') */
	/* 	p->u = va_arg(p->ap, unsigned int); */
}

void	pf_putc(t_convert *p)
{
	write(1, &p->c, sizeof(char));
	p->printcounter++;
}
void	pf_putspaces(int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
}

void	pf_putzero(int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
}

void pf_puts_precision(t_convert *p)
{

}
