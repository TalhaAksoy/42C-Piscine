#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = -1;
	argc++;
	while (argv[0][++i])
		write(1, &argv[0][i], 1);
	write(1, "\n", 1);
	return (0);
}
