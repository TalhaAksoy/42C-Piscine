#include"funcs.h"

int	ft_isvalid(char *argv)
{
	int i;

	i = -1;
	while(argv[++i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return(0);
	}
	return (1);
}
int	ft_isnumber(char c)
{
	return (c <= '9' && c >= '0');
}

int	ft_nbrlen(char *str)
{
	int	i;
	int	n;

	i = 0;
	while (str[i] == ' ')
		i++;
	n = i;
	while (str[i])
	{
		if (!ft_isnumber(str[i]))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		else
			i++;
	}
	return (i - n);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (dest[i] != '\0')
		i++;
	while (src[c] != '\0' || dest[i] != '\0')
	{
		dest[i] = src[c];
		c++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	x;

	i = 0;
	if (!(to_find[0]))
	{
		return (str);
	}
	while (str[i])
	{
		x = 0;
		while (str[i + x] == to_find[x] && str[i + x] != '\0')
		{
			if (!(to_find[x + 1]))
			{
				return (&str[i]);
			}
			x++;
		}
		i++;
	}
	return (0);
}

void	ft_str(char *a)
{
	int	b;

	b = -1;
	while (a[++b])
		write(1, &a[b], 1);
}
