int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	placeholder;

	placeholder = nb;
	i = 1;
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	if (power <= -1)
		return (0);
	while (power > i)
	{
		nb *= placeholder;
		i++;
	}
	return (nb);
}
