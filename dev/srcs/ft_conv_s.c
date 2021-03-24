char	*ft_conv_s(conv_specs)
{
	char	*string;

	/* ik vermoed dat je altijd eerst de field width wilt weten omdat die bepalend zal zijn voor het totale aantal karakters dat de string gaat bevatten, zodat je dat kunt malloccen.  */
	char	*ap_string = va_arg(conv_specs->ap, char *);
	if (conv_specs->width)
		string = malloc(conv_specs->width * sizeof(char) + 1;
	if (conv_specs->minus)
	{

	}
	return (ap_string);
}
