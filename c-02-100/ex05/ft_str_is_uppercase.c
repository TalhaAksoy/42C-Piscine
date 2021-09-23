int	ft_str_is_uppercase(char *str)
{
	int	sayac;

	sayac = 0;
	while (str[sayac] != '\0')
	{
		if (!(str[sayac] >= 65 && str[sayac] <= 90))
			return (0);
		sayac++;
	}
	return (1);
}
