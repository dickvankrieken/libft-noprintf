#include "../../../includes/ft_printf.h"

void	pf_putu_minus(t_convert *p)
{
	if (p->width)
	{
		if (p->precision)
		{
			pf_putu_minus_width_precision(p);
		}
		else
			pf_putu_minus_width(p);
	}
	else if (p->precision > ft_uintcountchars(p->d))
	{
		pf_putu_precision(p);
	}
	else
	{
		ft_putuint_fd((p->u), 1);
		/* zet alleen met minus zonder meer */
	}
}


void	pf_putu_minus_width_precision(t_convert *p)
{
	/* er is een minus, een width en een precision,
	   Minus: je begint met getallen en eindigt eventueel met spaties
	pf_putu_precision wordt eerst aangeroepen en i wordt gelijk gesteld aan de return waarde:  je print het getal in een bepaalde precision, dus eventueel met nullen ervoor, of....
eerst dus kijken of de precision langer of korter is dan het aantal getallen waaruit het getal bestaat. */
	int i;

	i = 0;
	i += pf_putu_precision(p);
	/* en nu komt er afhankelijk van de width nog een reeks spaties omdat hij links is uitgelijnd */
	while (i < p->width) /* zolang ie dus kleiner is dan die width nog spaties zetten */
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
}

/* deze functie gaat de unsigned int zetten met alleen een minus en een width, zonder precision */
void	pf_putu_minus_width(t_convert *p)
{
	/* er is een minus en een width, dus het getal gaat als eerst gezet worden en er komen eventueel nog wat spaties achter */
	int i;

	ft_putuint_fd((p->u), 1);
	i = 0;
	/* en nu komt er afhankelijk van de width nog een reeks spaties omdat hij links is uitgelijnd */
	while (i < p->width) /* zolang ie dus kleiner is dan die width nog spaties zetten */
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
}
