#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int	s;

	s = 0;
	while (str[s] != '\0')
	{
		if ((str[s] < 'A') || (str[s] > 'Z' && str[s] < 'a') || (str[s] > 'z'))
			return (0);
		s++;
	}
	return (1);
}
