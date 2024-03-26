#include "calculator.h"
#include <stdio.h>

int	main(int argc, const char *argv[])
{
	if (argc != 2)
		return (dprintf(2, "Usage: %s CALCUL\n", argv[0]), 1);
	return (0);
}
