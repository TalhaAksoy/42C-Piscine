/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saksoy <saksoy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:05:49 by saksoy            #+#    #+#             */
/*   Updated: 2021/09/22 16:45:31 by saksoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char	op;
	int		a;
	int		b;
	int		res;

	a = atoi(argv[1]);
	b = atoi(argv[3]);
	op = argv[2][0];
	if (argc == 4)
	{
		if (op == '+')
			res = a + b;
		else if (op == '-')
			res = a - b;
		else if (op == '/')
			res = a / b;
		else if (op == '*')
			res = a * b;
		else if (op == '%')
			res = a % b;
		printf("%d\n", res);
	}
	else
		write(1, "\n", 1);
}
