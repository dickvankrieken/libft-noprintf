#include "../../libft/libft.h"
#include "../../includes/ft_printf.h"

void	pf_putconversion(t_convert *p)
{
	if (p->type == 'c')
		pf_putc(p);
	if (p->type == 's')
		pf_puts(p);
	/* if (p->type == 'p') */

	if (p->type == 'd' || p->type == 'i')
		pf_putd(p);

	/* if (p->type == 'i') */

	/* if (p->type == 'u') */

	/* if (p->type == 'x') */

	/* if (p->type == 'X') */

}

void	pf_putc(t_convert *p)
{
	write(1, &p->c, sizeof(char));
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
