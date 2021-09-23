int	iss_alpha(char c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (1);
	if ((c >= 'A') && (c <= 'Z'))
		return (1);
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && !iss_alpha(str[i]))
			i++;
		if (str[i] != '\0' && ((str[i] >= 'a') && (str[i] <= 'z')))
			str[i] = ((str[i] - 'a') + 'A');
		i++;
		while (str[i] != '\0' && iss_alpha(str[i]))
		{
			if ((str[i] >= 'A') && (str[i] <= 'Z'))
				str[i] = ((str[i] - 'A') + 'a');
			i++;
		}
	}
	return (str);
}
