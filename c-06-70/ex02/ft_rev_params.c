#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc > 1)
	{
		while (argc - 1 > 0)
		{
			while (argv[argc - 1][i])
			{
				write(1, &argv[argc - 1][i], 1);
				i++;
			}
			i = 0;
			argc--;
			write(1, "\n", 1);
		}
	}
	return (0);
}
