#include "validate_define.h"

int	validate_line(char *line);

int	main(int argc, char *argv[])
{
	int	validate_flag;

	validate_flag = 0;
	for (int i = 1; i < argc; i++)
		if (validate_line(argv[i]) == 1)
			validate_flag = 1;
	return (validate_flag);
}
