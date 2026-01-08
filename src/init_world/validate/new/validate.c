
// #include "init_world_define.h"
#include <stddef.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <string.h>

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

typedef enum s_vectype
{
	IS_POINT,
	IS_UNIT,
	IS_COLOR
}	t_vectype;

typedef enum e_element_type
{
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
	TRIANGLE,
	NOTHING
}	t_element_type;

typedef t_result	(*t_skip)(const char *line, size_t *line_idx);

typedef struct s_element_info
{
	t_element_type	type;
	size_t			identifier_len;
	char			*format;// = "\x1b[0m""A [lighting ratio] ""\x1b[31m""R"",""\x1b[32m""G"",""\x1b[34m""B""\x1b[0m";
	const t_skip	*skip_arr;
}	t_element_info;

t_result	skip_spaces(const char *line, size_t *line_idx);
t_result	skip_point(const char *line, size_t *line_idx);
t_result	skip_color(const char *line, size_t *line_idx);
t_result	skip_unit(const char *line, size_t *line_idx);
t_result	skip_lighting_ratio(const char *line, size_t *line_idx);
t_result	skip_fov(const char *line, size_t *line_idx);
t_result	skip_until_end(const char *line, size_t *line_idx);
t_result	skip_diameter(const char *line, size_t *line_idx);

const t_skip	ambient_skips[] = {
	skip_spaces,
	skip_lighting_ratio,
	skip_spaces,
	skip_color,
	skip_until_end,
	NULL
};

const t_element_info	ambient_info = {
	.type = AMBIENT,
	.identifier_len = 1,
	.format = "A [lighting ratio(0-1)] [R,G,B(0-255)]",
	.skip_arr = ambient_skips
};

const t_skip	camera_skips[] = {
	skip_spaces,
	skip_point,
	skip_spaces,
	skip_unit,
	skip_spaces,
	skip_fov,
	skip_until_end,
	NULL
};

const t_element_info	camera_info = {
	.type = CAMERA,
	.identifier_len = 1,
	.format = "C [coordinate](x,y,z) [normalized orient vector](a,b,c) [fov](0-180)",
	.skip_arr = camera_skips
};

const t_skip	light_skips[] = {
	skip_spaces,
	skip_point,
	skip_spaces,
	skip_lighting_ratio,
	skip_spaces,
	skip_color,
	skip_until_end,
	NULL
};

const t_element_info	light_info = {
	.type = LIGHT,
	.identifier_len = 1,
	.format = "L [coordinate](x,y,z) [light brightness ratio](0-1) [R,G,B](0-255)",
	.skip_arr = light_skips
};

const t_skip	sphere_skips[] = {
	skip_spaces,
	skip_point,
	skip_spaces,
	skip_diameter,
	skip_spaces,
	skip_color,
	skip_until_end,
	NULL
};

const t_element_info	sphere_info = {
	.type = SPHERE,
	.identifier_len = 2,
	.format = "sp [coordinate](x,y,z) [diameter](>0) [R,G,B](0-255)",
	.skip_arr = sphere_skips
};

t_result	construct_t_result(char *_err_msg)
{
	t_result	result;

	bzero(&result, sizeof(t_result));
	if (_err_msg == NULL)
	{
		result.state = OK;
		result.value.ok = 0;
		return (result);
	}
	result.state = ERROR;
	result.value.err_msg = _err_msg;
	return (result);
}

t_result	skip_spaces(const char *line, size_t *line_idx)
{
	if (line[*line_idx] != ' ' && line[*line_idx] != '\t')
		return (construct_t_result("invalid format"));
	while (line[*line_idx] == ' ' || line[*line_idx] == '\t')
		(*line_idx)++;
	return (construct_t_result(NULL));
}

t_result	skip_value(const char *line, size_t *line_idx, t_vectype vectype, double *d)
{
	char	*endptr;

	*d = strtod(line + *line_idx, &endptr);
	if (endptr == line + *line_idx)
		return (construct_t_result("there is no vector value"));
	if (isnan(*d) || isinf(*d))
		return (construct_t_result("invalid vector value"));
	if (vectype == IS_COLOR && (*d < 0.0 || 255.0 < *d))
		return (construct_t_result("invalid color range"));
	*line_idx = (size_t)(endptr - line);
	return (construct_t_result(NULL));
}

t_result	skip_vec(const char *line, size_t *line_idx, t_vectype vectype)
{
	t_result	result;
	double		d3[3];
	int			d_idx;
	size_t		head_line_idx;

	bzero(d3, sizeof(double) * 3);
	d_idx = 0;
	head_line_idx = *line_idx;
	while (d_idx < 3)
	{
		result = skip_value(line, line_idx, vectype, d3 + d_idx);
		if (result.state == ERROR)
			return (result);
		if (++d_idx != 3)
			if(line[(*line_idx)++] != ',')
				return ((*line_idx)--, construct_t_result("there is no ','"));
	}
	if (vectype == IS_UNIT && 0.01 \
		<= fabs(pow(d3[0], 2) + pow(d3[1], 2) + pow(d3[2], 2) - 1))
	{
		(*line_idx) = head_line_idx;
		return (construct_t_result("not unit vector"));
	}
	return (construct_t_result(NULL));
}

t_result	skip_point(const char *line, size_t *line_idx)
{
	return (skip_vec(line, line_idx, IS_POINT));
}

t_result	skip_color(const char *line, size_t *line_idx)
{
	return (skip_vec(line, line_idx, IS_COLOR));
}

t_result	skip_unit(const char *line, size_t *line_idx)
{
	return (skip_vec(line, line_idx, IS_UNIT));
}

t_result	skip_range(const char *line, size_t *line_idx, double min, double max)
{
	double	d;
	char	*endptr;

	d = strtod(line + *line_idx, &endptr);
	if (endptr == line + *line_idx)
		return (construct_t_result("invalid format"));
	if (d < min || max < d)
		return (construct_t_result("out of range"));
	*line_idx = endptr - line;
	return (construct_t_result(NULL));
}

t_result	skip_lighting_ratio(const char *line, size_t *line_idx)
{
	return (skip_range(line, line_idx, 0, 1));
}

t_result	skip_fov(const char *line, size_t *line_idx)
{
	return (skip_range(line, line_idx, 0, 180));
}

t_result	skip_diameter(const char *line, size_t *line_idx)
{
	return (skip_range(line, line_idx, 0, INFINITY));
}

t_result	skip_until_end(const char *line, size_t *line_idx)
{
	skip_spaces(line, line_idx);
	if (line[*line_idx] != '\0' && line[*line_idx] != '\n')
		return (construct_t_result("invalid ending"));
	return (construct_t_result(NULL));
}

#include "libft.h"
#include <unistd.h>
# define GREEN "\033[92m"
# define RESET "\033[m"
void	err_point_out(char *line, size_t err_idx)
{
	size_t	i;

	i = 0;
	ft_putendl_fd(line, STDERR_FILENO);
	while (i < err_idx)
	{
		if (line[i++] == '\t')
			ft_putchar_fd('\t', STDERR_FILENO);
		else
			ft_putchar_fd(' ', STDERR_FILENO);
	}
	ft_putendl_fd(GREEN"^"RESET, STDERR_FILENO);
}

int	validate(char *line, const t_element_info elem_info)
{
	size_t		i;
	size_t		func_idx;
	t_result	result;

	i = elem_info.identifier_len;
	func_idx = 0;
	while (elem_info.skip_arr[func_idx])
	{
		result = elem_info.skip_arr[func_idx](line, &i);
		if (result.state == ERROR)
		{
			ft_putendl_fd(result.value.err_msg, STDERR_FILENO);
			ft_putendl_fd(elem_info.format, STDERR_FILENO);
			err_point_out(line, i);
			return (1);
		}
		func_idx++;
	}
	return (0);
}

int	match_identifier(const char *line, const char *id, size_t size)
{
	if (ft_strncmp(line, id, size) == 0 \
		&& line[size] == ' ' || line[size] == '\t')
		return (1);
	return (0);
}

t_element_info	get_elem_info(const char *line)
{
	if (match_identifier(line, "A", 1))
		return (ambient_info);
	if (match_identifier(line, "C", 1))
		return (camera_info);
	if (match_identifier(line, "L", 1))
		return (light_info);
	if (match_identifier(line, "sp", 2))
		return (sphere_info);
	return (((t_element_info){.type = NOTHING}));
}

int	main(int argc, char *argv[])
{
	t_result		result;
	t_element_info	elem_info;

	if (argc == 1)
		return (1);
	for (int i = 1; i < argc; i++) {
		elem_info = get_elem_info(argv[i]);
		if (elem_info.type == NOTHING)
		{
			ft_putendl_fd("invalid identifier", STDERR_FILENO);
			err_point_out(argv[i], 0);
			return (1);
		}
		if (validate(argv[i], elem_info))
			return (1);
	}
	return (0);
}
