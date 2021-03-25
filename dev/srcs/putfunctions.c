void ft_putrightjustification(t_convert *conv_specs)
{
	while (conv_specs->printcounter < conv_specs->width - conv_specs->arg_length)
	{

	}
}
/* probleem is nu: hoeveel putchars neerzetten terwijl je niet weet hoe veel ruimte dat variatische argument in moet gaan nemen... */
void ft_putleftjustification(t_convert *conv_specs)
{
	while (conv_specs->printcounter < conv_specs->width)
	{
		ft_putchar_fd(' ', 1);
		conv_specs->printcounter++;
	}
}

/* we gaan eerst een stukje verwerken wat voor ieder conversie type geldt: de width en de 0 en - flags.*/
void	ft_putconversion(t_convert *conv_specs)
{
	if (conv_specs->width)
	{
		if (conv_specs->minus)
		{
			/* als het goed is houd ft_put_arg bij hoeveel hij geprint heeft. Zodat vervolgens het restant volgezet kan worden met spaties of nullen */
			ft_put_arg(conv_specs);
			ft_putjustification(conv_specs);
		}
		else
		{

		}


		if (!conv_specs->minus)

			ft_put_arg(conv_specs);
	}


}
