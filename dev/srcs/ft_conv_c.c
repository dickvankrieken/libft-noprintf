

char	*ft_conv_c(conv_specs)
{
	char	*string;
	char	c;
	int	i;

	i = 0;
	/* eerst de field width omdat die het totale aantal karakters bepaald
dat de string gaat bevatten, zodat je de totale lengte van de string kunt alloceren.  */
	c = va_arg(conv_specs->ap, char);
	if (conv_specs->width)
	{
		string = malloc(conv_specs->width * sizeof(char) + 1;
		if (conv_specs->zero == 1)
		{
			string[i] = 'c';
		}
		else if (conv_specs->zero == 1);

	}

	return (string);
}


/* werk met void functies en gebruik zo min mogelijk return values, want dat maakt je code meer modulair */
