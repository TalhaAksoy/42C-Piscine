#include"funcs.h"

char	*ft_dict_read(char *arg)
{
	char	*str;
	int		fl;
	int		i;

	str = malloc(15000);
	fl = open(arg, O_RDONLY);
	read(fl, str, 1);
	i = 1;
	while (str[i - 1])
		read(fl, str + i++, 1);
	close(fl);
	free(str);
	return (str);
}

char	*ft_dict_find(char *str, char *key)
{
	char	*value;
	char	*ret_val;
	int		i;
	int		j;

	j = 0;
	value = ft_strstr(str, key);
	if (value == 0)
		return (0);
	ret_val = malloc(1000);
	while (value[j] <= '9' && value[j] >= '0' && value[j])
		j++;
	while (value[j] == ' ' || value[j] == ':')
		j++;
	i = j;
	while (value[i] != '\n')
	{
		ret_val[i - j] = value[i];
		i++;
	}
	ret_val[i] = '\0';
	return (ret_val);
}

void	ft_put_under_hundred(char *str, char *nbr, char *ret_val)
{
	char	nb[3];

	if (nbr[0] == '1')
		ft_strcat(ret_val, ft_dict_find(str, nbr));
	else if (nbr[0] == '0' && nbr[1] != '0')
		ft_strcat(ret_val, ft_dict_find(str, nbr + 1));
	else if (nbr[0] != '0')
	{
		nb[0] = nbr[0];
		nb[1] = '0';
		if (ft_dict_find(str, nb) == 0)
        	*ret_val = 2;
		else
			ft_strcat(ret_val, ft_dict_find(str, nb));
		if (nbr[1] != '0')
		{
			ft_strcat(ret_val, " ");
			if (ft_dict_find(str, nbr + 1) == 0)
				*ret_val = 2;
			else
				ft_strcat(ret_val, ft_dict_find(str, nbr + 1));
		}
	}
}

void	ft_put_hundreds(char *str, char *nbr, char *ret_val)
{
	char	nb[3];

	nb[1] = 0;
	nb[0] = nbr[0];
	if (nbr[0] != '0')
	{
		if (ft_dict_find(str, nb) == 0)
			*ret_val = 2;
		else
			ft_strcat(ret_val, ft_dict_find(str, nb));
		ft_strcat(ret_val, " ");
		if (ft_dict_find(str, "100") == 0)
			*ret_val = 2;
		else
			ft_strcat(ret_val, ft_dict_find(str, "100"));
		if (!(nbr[1] == '0' && nbr[2] == '0'))
			ft_strcat(ret_val, " ");
	}
	nb[0] = nbr[1];
	nb[1] = nbr[2];
	ft_put_under_hundred(str, nb, ret_val);
}

void	ft_put_order(char *str, char *nbr, int len, char *ret_val)
{
	char	*zeros;
	int		j;

	if (nbr[0] == 48 && nbr[1] == 48 && nbr[2] == 48)
	{
		ft_putnumber(str, nbr + 3, ret_val, 0);
		return ;
	}
	zeros = malloc(40);
	j = 1;
	zeros[0] = '1';
	while (len > 0)
	{
		zeros[j++] = '0';
		len--;
	}
	ft_strcat(ret_val, " ");
	if (ft_dict_find(str, zeros) == 0)
		*ret_val = 2;
	else
		ft_strcat(ret_val, ft_dict_find(str, zeros));
	if (ft_nbrlen(nbr) % 3 == 0)
		ft_putnumber(str, nbr + 3, ret_val, 0);
	else
		ft_putnumber(str, nbr + ft_nbrlen(nbr) % 3, ret_val, 0);
}

void	ft_putnumber(char *str, char *nbr, char *ret_val, int first_call)
{
	int		len;
	int		i;
	int		j;
	char	arr[4];

	if (!first_call && *ret_val == 0)
		return ;
	j = 0;
	i = 0;
	len = ft_nbrlen(nbr);
	while  (j != 3 - (len % 3) && len % 3 != 0)
		arr[j++] = '0';
	while (nbr[i] == ' ')
		i++;
	while (len % 3 != 0 || j == 0)
	{
		arr[j++] = nbr[i++];
		len--;
	}
	if (!first_call && !(nbr[0] == 48 && nbr[1] == 48 && nbr[2] == 48))
		ft_strcat(ret_val, " ");
	ft_put_hundreds(str, arr, ret_val);
	j = 1;
	if (len > 0)
		ft_put_order(str, nbr, len, ret_val);
}
