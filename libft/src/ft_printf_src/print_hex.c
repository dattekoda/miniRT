/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:27:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/12 20:04:43 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_output.h"

static int	set_hex_ctx(t_ctx *ctx, t_arg arg, t_spec spec);
static char	*set_prefix(t_spec spec);

int	print_hex(t_arg arg, t_spec spec)
{
	t_ctx	ctx;

	if (set_hex_ctx(&ctx, arg, spec) == ERROR)
		return (ERROR);
	if (output(ctx, spec) == ERROR)
		return (ERROR);
	free(ctx.base_str);
	return (ctx.output_len);
}

static int	set_hex_ctx(t_ctx *ctx, t_arg arg, t_spec spec)
{
	ctx->val = (long)arg.u;
	ctx->sign = 0;
	ctx->prefix = set_prefix(spec);
	ctx->base_str = ltox(ctx->val, (spec.type == HEX_UP));
	if (!ctx->base_str)
		return (ERROR);
	ctx->base_len = ft_strlen(ctx->base_str);
	ctx->pad.zero = set_zero_pad(ctx, spec);
	ctx->digit_len = set_digit_len(*ctx);
	ctx->pad.space = set_space_pad(spec, *ctx);
	ctx->output_len = ctx->pad.space + ctx->digit_len;
	return (0);
}

static char	*set_prefix(t_spec spec)
{
	if (spec.flag & ALT_FORM)
	{
		if (spec.type == HEX_LOW)
			return ("0x");
		else if (spec.type == HEX_UP)
			return ("0X");
	}
	return ("");
}

// #include <stdio.h>
// int main(void)
// {
// 	// t_dec_ctx ctx;
// 	t_arg arg;
// 	arg.i = 255;
// 	t_spec spec;
// 	spec.flag = 127 - LEFT_JUST;
// 	spec.prec = 10;
// 	spec.width = 15;
// 	spec.type = HEX_LOW;
// 	//init_dec_ctx(&ctx, arg, spec);
// 	//printf("val: %ld, sign: %c, num_str: %s", ctx.val, ctx.sign, ctx.num_str);
// 	int rev = print_hex(arg, spec);
// 	printf("\nreturn value: %d\n", rev);
// }
