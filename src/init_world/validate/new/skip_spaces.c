
// #include "init_world_define.h"
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
	while (line[*i_ptr] == ' ' || line[*i_ptr] == '\t')
		(*i_ptr)++;
	result.state = OK;
	result.value.ok = 0;
	return (result);
}

typedef t_result	(*t_skip)(const char *line, size_t *i_ptr);

t_skip	*ambient_skips= {
	skip_spaces,
	NULL
};

int	validate_ambient(char *line)
{
	size_t	i = 0;
	size_t	func_idx = 0;
	t_result	result;

	while (ambient_skips[func_idx])
	{
		result = ambient_skips[func_idx](line, &i);
		if (result.state == ERROR)
		{
			printf("miniRT: ambient format: ");
			printf("%s\n", result.value.err_msg);
			err_point_out(line, i);
			return (1);
		}
		func_idx++;
	}
	return (0);
}


#include <stdio.h>
int	main()
{
	t_result	result;
	size_t	i;
	char *line = "  aaaaa  a";

	i = 4;
	result = skip_spaces(line, &i);
	printf("%s\n", line + i);
	if (result.state == OK)
		printf("return value: %d\n", result.value.ok);
	else
		printf("%s\n", result.value.err_msg);
	return (0);
}
