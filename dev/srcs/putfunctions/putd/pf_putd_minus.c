#include "../../../includes/ft_printf.h"

void	pf_putd_minus(t_convert *p)
{
	if (p->width)
	{
		if (p->precision)
		{
			pf_putd_minus_width_precision(p);
		}
		else
			pf_putd_minus_width(p);
	}
	else if (p->precision > (int)ft_strlen(ft_itoa(p->d)))
	{
		pf_putd_precision(p);
	}
	else
	{
		ft_putstr_fd(ft_itoa(p->d), 1);
		/* zet alleen met minus zonder meer */
	}
}


void	pf_putd_minus_width_precision(t_convert *p)
{
	/* er is een minus, een width en een precision,
	   Minus: je begint met getallen en eindigt eventueel met spaties
	pf_putd_precision wordt eerst aangeroepen en i wordt gelijk gesteld aan de return waarde:  je print het getal in een bepaalde precision, dus eventueel met nullen ervoor, of....
eerst dus kijken of de precision langer of korter is dan het aantal getallen waaruit het getal bestaat. */
	int i;

	i = 0;
	i += pf_putd_precision(p);
	/* en nu komt er afhankelijk van de width nog een reeks spaties omdat hij links is uitgelijnd */
	while (i < p->width) /* zolang ie dus kleiner is dan die width nog spaties zetten */
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
}

/* deze functie gaat de d/i zetten met alleen een minus en een width, zonder precision */
void	pf_putd_minus_width(t_convert *p)
{
	/* er is een minus en een width, dus het getal gaat als eerst gezet worden en er komen eventueel nog wat spaties achter */
	int i;

	ft_putstr_fd(ft_itoa(p->d), 1);
	i = 0;
	/* en nu komt er afhankelijk van de width nog een reeks spaties omdat hij links is uitgelijnd */
	while (i < p->width) /* zolang ie dus kleiner is dan die width nog spaties zetten */
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
}

/* deze functie is onnodig, is hetzelfde als pf_putd_precision, want minus is betekingloos zonder width */
/*******************************************************************************************************************************************************************************************************************************/
/* void	pf_putd_minus_precision(t_convert *p)																																												   */
/* {																																																						   */
/* 	/\* er is een minus en een precision. Minus dus het getal wordt eerst gezet, en een precision betekent dat als die groter is dan de strlen van het getal dan gaat ie aangevuld worden met vooraanstaande nullen. *\/	   */
/* 																																																							   */
/* }																																																						   */
/*******************************************************************************************************************************************************************************************************************************/
