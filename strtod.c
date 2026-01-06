#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	main(int argc, char *argv[])
{
	char	*line;

	(void)argc;
	printf("%f\n", ft_strtod(argv[1], &line));
	printf("%s\n", line);
}