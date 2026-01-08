
#include "init_world_define.h"
#include <stddef.h>

enum e_result
{
	OK,
	ERROR
};

union u_result
{
	int		ok;
	char	*err_msg;
};

typedef struct s_result
{
	enum e_result	state;
	union u_result	value;
}	t_result;

t_result	skip_spaces(const char *line, size_t *i_ptr)
{
	t_result	result;

	if (line[*i_ptr] != ' ' && line[*i_ptr] != '\t')
	{
		result.state = ERROR;
		result.value.err_msg = "need space";
		return (result);
	}
	while (line[*i_ptr] == ' ' )
	result.state = OK;
	result.value.ok = 0;
	return (result);
}

int	main()
{
	skip_spaces()
	return (0);
}
