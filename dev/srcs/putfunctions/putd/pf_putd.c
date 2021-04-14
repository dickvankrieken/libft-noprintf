void	pf_putd(t_convert *p)
{
/* put d gaat een getal zetten
als er een - is dan wordt de conversie links-uitgelijnd binnen de field
als er een 0 flag is , dan worden er leading nullen geplaatst
als er een 0 en een - is, dan wordt de 0 flag genegeerd.
Voor d, i, o, u, x, en X - als er een precisie gespecifieerd is dan wordt de 0 flag genegeerd.
En voor andere conversies is het gedrag ongedefinieerd.
Het int argument wordt geconverteerd naar een signed decimal in de stijl van [-]dddd de precisie specifieerd het minimale aantal getallen dat zal verschijnen; als de waarde die geconverteerd gaat worden in minder getallen gerepresenteerd kan worden, dan zal het uitgebreid worden met vooraanstaande nullen. De standaard precisie is 1. Het resultaat van het converteren van een 0 waarde met een precisie van 0, is geen karakters */


		if (p->minus)
		{
			if (p->width > ft_strlen(ft_itoa(p->d)))
				if (p->precision)

			if (p->precision > ft_strlen(ft_itoa(p->d)))
		}
		else if (p->zero) /* No minus */
		if (p->width)
		if (p->precision)
		pf_putd_noflags();
}
