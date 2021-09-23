#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	w;

	i = 0;
	w = 1;
	if (argc >= 2)
	{
		while (argv[w])
		{
			while (argv[w][i])
			{
				write (1, &argv[w][i], 1);
				i++;
			}
			write (1, "\n", 1);
			i = 0;
			w++;
		}
	}
	return (0);
}
