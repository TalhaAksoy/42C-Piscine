#include <stdlib.h>
#include <unistd.h>
#include"funcs.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char *str;
	char *nbr;
	char *ret_val;

	ret_val = (char *)malloc(10000);
	if (argc == 2)
	{
		str = ft_dict_read("numbers.dict.txt");
		nbr = ft_delspandzero(argv[1]);
		if (!ft_isvalid(nbr))
		{
			ft_str("Error\n");
			return (0);
		}
		ft_putnumber(str, nbr, ret_val, 1);
	}
	else if (argc == 3)
	{
		str = ft_dict_read(argv[1]);
        nbr = ft_delspandzero(argv[2]);
        if (!ft_isvalid(nbr))
        {
            ft_str("Error");
            return (0);
        }
        ft_putnumber(str, nbr, ret_val, 1);
    }
	else
		ft_str("Error");
	if (*ret_val != 2)
		ft_str(ret_val);
	else
		ft_str("Dict Error");
	ft_str("\n");
}
