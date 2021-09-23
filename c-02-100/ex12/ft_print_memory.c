#include <unistd.h>

void	w_hex(char *ch, int a)
{	
	unsigned char	k;
	char			c;
	char			b;
	char			*t;
	int				i;

	t = "0123456789abcdef";
	i = 0;
	while (i < a)
	{
		k = (unsigned char) *ch;
		c = k % 0x10;
		b = k / 0x10;
		ch++;
		write(1, t + b, 1);
		write(1, t + c, 1);
		i++;
	}
}

void	w_addr(void *ch, int a)
{	
	unsigned long long int	k;
	unsigned char			c;
	unsigned char			b;
	char					*t;
	int						i;

	k = (unsigned long long int) ch;
	i = 0;
	b = 0;
	if (a < 0)
		return ;
	t = "0123456789abcdef";
	while (0 < a)
	{
		c = (k >> (8 * (a - 1))) % 0x10;
		b = (k >> (8 * (a - 1)));
		b /= 0x10;
		write(1, t + b, 1);
		write(1, t + c, 1);
		a--;
	}
}

void	w_ch(char *ch, unsigned int sz)
{
	unsigned int	i;
	char			c;

	i = 0;
	while (i < sz)
	{
		c = ch[i];
		if (!(c >= ' ' && c <= '~'))
			c = '.';
		write(1, &c, 1);
		i++;
	}
}

void	w_line(void *addr, unsigned int size)
{
	unsigned int	j;
	int				k;
	char			*ch;

	ch = "                                                     ";
	k = size % 2;
	j = 0;
	w_addr(addr, 8);
	write(1, ": ", 2);
	while (j < size / 2)
	{
		w_hex(addr + (2 * j), 2);
		write(1, " ", 1);
		j++;
	}
	if (k == 1)
	{
		w_hex(addr + (j * 2), 1);
		write(1, " ", 1);
	}
	write(1, ch, ((16 - size) * 2 + (16 - size) / 2));
	w_ch(addr, size);
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	d;
	unsigned int	i;
	char			*h;
	void			*addr2;

	h = addr;
	if (size == 0)
		return (0);
	i = 0;
	addr2 = addr;
	i = 0;
	d = size / 16;
	while (i < d)
	{
		w_line(addr2, 16);
		addr2 += 16;
		i++ ;
	}
	d = size % 16;
	w_line(addr2, d);
	return (addr);
}
