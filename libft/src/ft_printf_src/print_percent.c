/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:12:11 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/12 14:40:40 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_output.h"

int	print_percent(void)
{
	if (ft_putchar_safe('%') == -1)
		return (ERROR);
	return (1);
}

// #include <stdio.h>
// int main(void)
// {
// 	t_dec_ctx ctx;
// 	t_arg arg;
// 	arg.i = 255;
// 	t_spec spec;
// 	spec.flag = 127 - LEFT_JUST;
// 	spec.prec = 10;
// 	spec.width = 15;
// 	spec.type = PERCENT;
// 	init_dec_ctx(&ctx, arg, spec);
// 	printf("val: %ld, sign: %c, num_str: %s", ctx.val, ctx.sign, ctx.num_str);
// 	int rev = print_percent(spec);
// 	printf("\nreturn value: %d\n", rev);
// 	int rev = printf("%10%");
// 	printf("\nreturn value: %d\n", rev);　
// }