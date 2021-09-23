/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saksoy <saksoy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 09:27:29 by saksoy            #+#    #+#             */
/*   Updated: 2021/09/23 09:39:36 by saksoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_rot_13(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 'A' && str[i] <= 'M')
			ft_putchar(str[i] += 13);
		else if (str[i] >= 'N' && str[i] <= 'Z')
			ft_putchar(str[i] -= 13);
		else if (str[i] >= 'a' && str[i] <= 'm')
			ft_putchar(str[i] += 13);
		else if (str[i] >= 'n' && str[i] <= 'z')
			ft_putchar(str[i] -= 13);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_rot_13(argv[1]);
	ft_putchar('\n');
	return (0);
}
