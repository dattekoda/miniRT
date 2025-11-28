/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:48:26 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/11 21:57:48 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_output.h"

static int	set_u_int_ctx(t_ctx *ctx, t_arg arg, t_spec spec);

int	print_u_int(t_arg arg, t_spec spec)
{
	t_ctx	ctx;

	if (set_u_int_ctx(&ctx, arg, spec) == ERROR)
		return (ERROR);
	if (output(ctx, spec) == ERROR)
		return (ERROR);
	free(ctx.base_str);
	return (ctx.output_len);
}

static int	set_u_int_ctx(t_ctx *ctx, t_arg arg, t_spec spec)
{
	ctx->val = (long)arg.u;
	ctx->sign = 0;
	ctx->prefix = NULL;
	ctx->base_str = ft_ltoa(ctx->val);
	if (!ctx->base_str)
		return (ERROR);
	ctx->base_len = ft_strlen(ctx->base_str);
	ctx->pad.zero = set_zero_pad(ctx, spec);
	ctx->digit_len = ctx->pad.zero + ctx->base_len;
	ctx->pad.space = set_space_pad(spec, *ctx);
	ctx->output_len = ctx->pad.space + ctx->digit_len;
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	// t_dec_ctx ctx;
// 	t_arg arg;
// 	arg.u = (unsigned int)INT_MAX + 1;
// 	t_spec spec;
// 	spec.flag = 127;
// 	spec.prec = 15;
// 	spec.width = 20;
// 	spec.type = U_INT;
// 	//init_dec_ctx(&ctx, arg, spec);
// 	//printf("val: %ld, sign: %c, num_str: %s", ctx.val, ctx.sign, ctx.num_str);
// 	int rev = print_u_int(arg, spec);
// 	printf("\nreturn value: %d\n", rev);
// }
