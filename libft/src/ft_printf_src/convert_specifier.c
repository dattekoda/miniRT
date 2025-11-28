/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_specifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 06:37:32 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/12 19:40:26 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_format.h"

static void	reset_spec(t_spec *spec);
static int	is_error(t_spec spec);
static int	get_width_arg(int arg, t_spec *spec);

size_t	convert_specifier(const char **fmt, va_list ap)
{
	t_arg	arg;
	t_spec	spec;
	size_t	cnt;

	reset_spec(&spec);
	get_format_spec(fmt, &spec);
	if (is_error(spec))
		return (ERROR);
	if (spec.flag & WIDTH_ARG)
		spec.width = get_width_arg(va_arg(ap, int), &spec);
	if (spec.flag & PREC_ARG)
		spec.prec = va_arg(ap, int);
	pop_varg(&arg, spec.type, ap);
	cnt = print_arg(arg, spec);
	return (cnt);
}

static int	get_width_arg(int arg, t_spec *spec)
{
	if (arg == INT_MIN)
		return (ERROR);
	if (arg < 0)
	{
		spec->flag |= LEFT_JUST;
		arg = -arg;
	}
	return (arg);
}

static int	is_error(t_spec spec)
{
	if (spec.flag == ERROR)
		return (1);
	if (spec.width == ERROR)
		return (1);
	if (spec.prec == ERROR)
		return (1);
	if (spec.type == ERROR)
		return (1);
	return (0);
}

static void	reset_spec(t_spec *spec)
{
	spec->flag = 0;
	spec->width = DEFAULT;
	spec->prec = DEFAULT;
	spec->type = DEFAULT;
}

// #include <stdio.h>
// void print_varg(const char *fmt, ...);
// int main()
// {
// 	print_varg("%d", 10);
// }
// void print_varg(const char *fmt, ...)
// {
// 	va_list ap;
// 	va_start(ap, fmt);
// 	fmt++;
// 	convert_specifier(&fmt, ap);
// 	va_end(ap);
// }