/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_z.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saksoy <saksoy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:47:24 by saksoy            #+#    #+#             */
/*   Updated: 2021/09/23 17:20:24 by saksoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	putz(void)
{
	write(1, "z", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	x;

	i = -1;
	x = 0;
	if (argc >= 2)
	{
		while (argv[++x])
		{
			if (putz() == 0)
				break ;
			while (argv[x][++i])
			{
				if (argv[x][i] == 'z')
					putz();
				else if (argv[x][i] != 'z')
					putz();
			}
		}
	}
	else
		putz();
	return (0);
}
