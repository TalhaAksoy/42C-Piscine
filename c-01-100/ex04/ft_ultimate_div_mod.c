void	ft_ultimate_div_mod(int *a, int *b)
{
	int	x;
	int	y;

	if (!(*b == 0))
	{
		x = (*a) / (*b);
		y = (*a) % (*b);
		*b = y;
		*a = x;
	}
}
