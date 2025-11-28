/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:25:52 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/10/03 10:47:23 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_output.h"

int	print_arg(t_arg arg, t_spec spec)
{
	int	cnt;

	if (spec.type == CHAR)
		cnt = print_char(arg, spec);
	else if (spec.type == DEC)
		cnt = print_dec(arg, spec);
	else if (spec.type == U_INT)
		cnt = print_u_int(arg, spec);
	else if (spec.type == HEX_LOW || spec.type == HEX_UP)
		cnt = print_hex(arg, spec);
	else if (spec.type == STR)
		cnt = print_str(arg, spec);
	else if (spec.type == PTR)
		cnt = print_ptr(arg, spec);
	else if (spec.type == PERCENT)
		cnt = print_percent();
	else
		cnt = ERROR;
	return (cnt);
}

// #include <stdio.h>
// void	print_varg(const char *fmt, ...);
// int main(void)
// {
// 	t_arg arg;
// 	arg.i = 'X';
// 	t_spec spec;
// 	spec.flag = 0;
// 	spec.prec = DEFAULT;
// 	spec.width = DEFAULT;
// 	spec.type = CHAR;
// 	print_arg(arg, spec);
// }
