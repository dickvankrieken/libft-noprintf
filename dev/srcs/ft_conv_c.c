/* eerst de field width omdat die het totale
 aantal karakters bepaald
dat de string gaat bevatten, zodat
 je de totale lengte van de string kunt alloceren.  */

int	*ft_conv_c(t_convert conv_specs)
{
	char	c;
	int		i;

	i = 0;
	c = va_arg(conv_specs->ap, char);
	while (i < conv_specs->width)
	{
		if (conv_specs->minus == 1)
		{
			if (i == 0)
			{
				i++;
				ft_putchar_fd(c);
			}
			else
			{
				i++;
				ft_putchar_fd(' ');
			}
		}
		else if (conv_specs->zero == 1)
		{
			while (i < conv_specs->width - 1)
			{
				string[i] = '0';
				i++;
			}
			if (i == conv_specs->width)
			{
				ft_putchar_fd(c, 1);
			}
		}
	}
	if (!conv_specs->width)
		ft_putchar_fd(c, 1);
	return (i);
}
/* werk met void functies en gebruik zo min mogelijk return values,
want dat maakt je code meer modulair */
