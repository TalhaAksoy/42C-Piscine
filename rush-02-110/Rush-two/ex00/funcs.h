#ifndef	FT_FUNCS_H
#define FT_FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char	*ft_delspandzero(char *argv);
int		ft_isvalid(char *argv);
int		ft_isnumber(char c);
int		ft_nbrlen(char *str);
char	*ft_strstr(char *str, char *to_find);
void	ft_str(char *a);
char	*ft_dict_read(char *arg);
char	*ft_dict_find(char *str, char *key);
void	ft_put_under_hundred(char *str, char *nbr, char *ret_val);
void	ft_put_hundreds(char *str, char *nbr, char *ret_val);
void	ft_putnumber(char *str, char *nbr, char *ret_val,  int first_call);
char	*ft_strcat(char *dest, char *src);

#endif
