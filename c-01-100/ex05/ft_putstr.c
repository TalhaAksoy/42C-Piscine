#include <unistd.h>

void	ft_putchar(char x)
{
	write(1, &x, 1);
}

void	ft_putstr(char *str)
{
	unsigned int	sayac;

	sayac = 0;
	while (str[sayac] != '\0')
	{
		ft_putchar(str[sayac]);
		sayac++;
	}
}
