/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 01:17:47 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/11 21:55:32 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_output.h"

static int	set_dec_ctx(t_ctx *ctx, t_arg arg, t_spec spec);

int	print_dec(t_arg arg, t_spec spec)
{
	t_ctx	ctx;

	if (set_dec_ctx(&ctx, arg, spec) == ERROR)
		return (ERROR);
	if (output(ctx, spec) == ERROR)
		return (ERROR);
	free(ctx.base_str);
	return (ctx.output_len);
}

static int	set_dec_ctx(t_ctx *ctx, t_arg arg, t_spec spec)
{
	ctx->val = (long)arg.i;
	ctx->sign = set_sign_abs(&ctx->val, spec.flag);
	ctx->prefix = NULL;
	ctx->base_str = ft_ltoa(ctx->val);
	if (!ctx->base_str)
		return (ERROR);
	ctx->base_len = ft_strlen(ctx->base_str);
	ctx->pad.zero = set_zero_pad(ctx, spec);
	ctx->digit_len = !!ctx->sign + ctx->pad.zero + ctx->base_len;
	ctx->pad.space = set_space_pad(spec, *ctx);
	ctx->output_len = ctx->pad.space + ctx->digit_len;
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	// t_dec_ctx ctx;
// 	t_arg arg;
// 	arg.i = 10;
// 	t_spec spec;
// 	spec.flag = 127 - LEFT_JUST;
// 	spec.prec = 5;
// 	spec.width = 10;
// 	spec.type = DEC;
// 	//init_dec_ctx(&ctx, arg, spec);
// 	//printf("val: %ld, sign: %c, num_str: %s", ctx.val, ctx.sign, ctx.num_str);
// 	int rev = print_dec(arg, spec);
// 	printf("\nreturn value: %d\n", rev);
// }
