unsigned int	length(char *str)
{
	unsigned int	sayac;

	sayac = 0;
	while (*str)
	{
		sayac++;
		str++;
	}
	return (sayac);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	x;
	unsigned int	y;

	if (size <= length(dest))
		return (size + length(src));
	x = length(dest);
	y = 0;
	while (src[y] && x + 1 < size)
	{
		dest[x] = src[y];
		x++;
		y++;
	}
	dest[x] = '\0';
	return (length(dest) + length(&src[y]));
}
