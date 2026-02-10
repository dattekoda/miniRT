#include "libft.h"
#include <unistd.h>

static void	print_remaining(size_t yi)
{
	ft_putstr_fd("\rScanlines remaining: ", STDERR_FILENO);
	ft_putnbr_fd((int)yi, STDERR_FILENO);
}

int main(void)
{
	for (size_t i = 0; i < 10000; i++)
	{
		print_remaining(i);
		sleep(1);
	}
}