/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saksoy <saksoy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:35:51 by saksoy            #+#    #+#             */
/*   Updated: 2021/09/22 16:56:46 by saksoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ulstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 32 && str[i] <= 127)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
			else if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
			write(1, &str[i], 1);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_ulstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}
