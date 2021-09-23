#include "funcs.h"

char	*ft_delspandzero(char *str)
{
	int i;
	int j;
	char *strcp;

	strcp = malloc(100);
	j = 0;
	i = 0;
	while(str[i] == ' ' || str[i] == '0')
		i++;
	while(str[i])
		strcp[j++] = str[i++];
	free(strcp);
	return(strcp);
}