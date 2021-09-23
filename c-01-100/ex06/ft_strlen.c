#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int		count;
	char	next_char;

	count = 0;
	while (true)
	{
		next_char = *str;
		if (next_char == '\0')
		{
			return (count);
		}
		count += 1;
		str++;
	}
}
