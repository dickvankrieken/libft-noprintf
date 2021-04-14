/*
put d gaat een getal zetten
als er een - is dan wordt de conversie links-uitgelijnd binnen de field
als er een 0 flag is , dan worden er leading nullen geplaatst
als er een 0 en een - is, dan wordt de 0 flag genegeerd.
Voor d, i, o, u, x, en X - als er een precisie gespecifieerd is dan wordt de 0 flag genegeerd.
En voor andere conversies is het gedrag ongedefinieerd.
Het int argument wordt geconverteerd naar een signed decimal in de stijl van [-]dddd de precisie specifieerd het minimale aantal getallen dat zal verschijnen; als de waarde die geconverteerd gaat worden in minder getallen gerepresenteerd kan worden, dan zal het uitgebreid worden met vooraanstaande nullen. De standaard precisie is 1. Het resultaat van het converteren van een 0 waarde met een precisie van 0, is geen karakters
*/

void	pf_putd(t_convert *p)
{
		if (p->minus)
		{
			pf_putd_minus(p);
		}
		else if (p->zero)
		{
			pf_putd_zero(p);
		}
		else if (p->width)
		{
			/* zet een d/i die alleen een width heeft */
		}
		else if (p->precision)
		{
			/* zet een d/i die alleen een precision heeft */
		}
		else
		{
			ft_putstr_fd(ft_itoa(p->d, 1)); /* ik denk nu dat dit alles is voor het zetten van d/i zonder flags dus dat we geen pf_putd_noflags() functie nodig hebben. */
		}
}

/*
helperfuncties in andere files

in pf_putd_minus.c
void	pf_putd_minus_width_precision(t_convert *p);
void	pf_putd_minus_width(t_convert *p);

in pf_putd_zero.c
void	pf_putd_zero_width_precision(t_convert *p);
void	pf_putd_zero_width(t_convert *p);
void	pf_putd_zero_precision(t_convert *p);
void	pf_putd_zero(t_convert *p);
*/
