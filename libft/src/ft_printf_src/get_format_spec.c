/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_spec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 07:15:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/11 21:34:07 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_format.h"

static int	get_flag(const char **fmt);
static int	get_width(const char **fmt);
static int	get_prec(const char **fmt);
static int	get_type(const char **fmt);

void	get_format_spec(const char **fmt, t_spec *spec)
{
	spec->flag = get_flag(fmt);
	if (**fmt == '*')
	{
		spec->flag |= WIDTH_ARG;
		(*fmt)++;
	}
	else if (ft_isdigit(**fmt))
		spec->width = get_width(fmt);
	if (**fmt == '.')
	{
		(*fmt)++;
		if (**fmt == '*')
		{
			spec->flag |= PREC_ARG;
			(*fmt)++;
		}
		else
			spec->prec = get_prec(fmt);
	}
	spec->type = get_type(fmt);
}

static int	get_flag(const char **fmt)
{
	size_t	flag;

	flag = 0;
	while (ft_strchr("# +-0", **fmt))
	{
		if (**fmt == '#')
			flag |= ALT_FORM;
		else if (**fmt == ' ')
			flag |= BLANK_POS;
		else if (**fmt == '+')
			flag |= SIGNED;
		else if (**fmt == '-')
			flag |= LEFT_JUST;
		else if (**fmt == '0')
			flag |= ZERO_PADD;
		(*fmt)++;
	}
	return (flag);
}

static int	get_width(const char **fmt)
{
	int	width;
	int	digit;

	width = 0;
	while (ft_isdigit(**fmt))
	{
		digit = **fmt - '0';
		if (width > (INT_MAX - digit) / 10)
			return (ERROR);
		width = width * 10 + digit;
		(*fmt)++;
	}
	return (width);
}

static int	get_prec(const char **fmt)
{
	int	prec;
	int	digit;

	prec = 0;
	while (ft_isdigit(**fmt))
	{
		digit = **fmt - '0';
		if (prec > (INT_MAX - digit) / 10)
			return (ERROR);
		prec = prec * 10 + digit;
		(*fmt)++;
	}
	return (prec);
}

static int	get_type(const char **fmt)
{
	int	type;

	type = PERCENT;
	if (**fmt == 'c')
		type = CHAR;
	else if (**fmt == 'd' || **fmt == 'i')
		type = DEC;
	else if (**fmt == 'u')
		type = U_INT;
	else if (**fmt == 'x')
		type = HEX_LOW;
	else if (**fmt == 'X')
		type = HEX_UP;
	else if (**fmt == 's')
		type = STR;
	else if (**fmt == 'p')
		type = PTR;
	else if (**fmt == '%')
		type = PERCENT;
	else
		(*fmt)--;
	(*fmt)++;
	return (type);
}

// #include <stdio.h>
// int main(void)
// {
// 	char	*fmt1 = "# +-0100.55s";
// 	const char	*tmp = fmt1;
// 	t_spec spec;
// 	spec.flag = 0;
// 	spec.width = 0;
// 	spec.prec = 0;
// 	spec.type = 0;
// 	get_format_spec(&tmp, &spec);
// 	printf("len: %lu\n", tmp - fmt1);
// 	printf("flag: %d\n", spec.flag);
// 	printf("width: %d\n", spec.width);
// 	printf("prec: %d\n", spec.prec);
// 	printf("type: %d\n", spec.type);
// 	printf("\n");
// 	char	*fmt2 = "10.d";
// 	const char *tmp2 = fmt2;
// 	spec.flag = 0;
// 	spec.width = 0;
// 	spec.prec = 0;
// 	spec.type = 0;
// 	get_format_spec(&tmp2, &spec);
// 	printf("len: %lu\n", tmp2 - fmt2);
// 	printf("flag: %d\n", spec.flag);
// 	printf("width: %d\n", spec.width);
// 	printf("prec: %d\n", spec.prec);
// 	printf("type: %d\n", spec.type);
// 	printf("\n");
// 	char	*fmt3 = ".*s";
// 	const char *tmp3 = fmt3;
// 	spec.flag = 0;
// 	spec.width = 0;
// 	spec.prec = 0;
// 	spec.type = 0;
// 	get_format_spec(&tmp3, &spec);
// 	printf("len: %lu\n", tmp3 - fmt3);
// 	printf("flag: %d\n", spec.flag);
// 	printf("width: %d\n", spec.width);
// 	printf("prec: %d\n", spec.prec);
// 	printf("type: %d\n", spec.type);
// 	printf("\n");
// 	char	*fmt4 = "9.6s";
// 	const char *tmp4 = fmt4;
// 	spec.flag = 0;
// 	spec.width = 0;
// 	spec.prec = 0;
// 	spec.type = 0;
// 	get_format_spec(&tmp4, &spec);
// 	printf("len: %lu\n", tmp4 - fmt4);
// 	printf("flag: %d\n", spec.flag);
// 	printf("width: %d\n", spec.width);
// 	printf("prec: %d\n", spec.prec);
// 	printf("type: %d\n", spec.type);
// }
