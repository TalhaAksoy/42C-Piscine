#include <stdio.h>

void *ft_print_memory(void *addr, unsigned int size);

int main(void)
{
	char a[225] = "asş\0ldkflhsadlfjkaşslkdjf aodfgşkl\nasdjfşl şlak011243sjdflşkasd";
	ft_print_memory(a,100);
}
