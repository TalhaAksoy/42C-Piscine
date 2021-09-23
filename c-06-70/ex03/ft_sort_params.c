#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char x)
{
	write(1, &x, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	ft_print_ar(char **arr)
{
	while (*arr)
	{
		ft_putstr(*arr++);
		ft_putchar('\n');
	}
}

void	ft_sort_ascii(char **val, int nb)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < (nb - 1))
	{
		j = 0;
		while (val[i][j] == val[i + 1][j])
			j++;
		if (val[i][j] > val[i + 1][j])
		{
			tmp = val[i];
			val[i] = val[i + 1];
			val[i + 1] = tmp;
			i = 0;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_sort_ascii(argv, argc);
		ft_print_ar(argv + 1);
	}
	return (0);
}
