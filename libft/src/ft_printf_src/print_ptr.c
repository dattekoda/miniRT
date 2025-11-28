/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:33:48 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/11 21:57:15 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_output.h"

static int	set_ptr_ctx(t_ctx *ctx, t_arg arg, t_spec spec);
static char	*set_ptr(t_arg arg);
static char	set_ptr_sign(t_spec spec);

int	print_ptr(t_arg arg, t_spec spec)
{
	t_ctx	ctx;

	if (set_ptr_ctx(&ctx, arg, spec) == ERROR)
		return (ERROR);
	if (output(ctx, spec) == ERROR)
		return (ERROR);
	if (ctx.val)
		free(ctx.base_str);
	return (ctx.output_len);
}

static int	set_ptr_ctx(t_ctx *ctx, t_arg arg, t_spec spec)
{
	ctx->val = (long)arg.p;
	ctx->sign = set_ptr_sign(spec);
	ctx->prefix = "0x";
	ctx->base_str = set_ptr(arg);
	if (!ctx->base_str)
		return (ERROR);
	ctx->base_len = ft_strlen(ctx->base_str);
	ctx->pad.zero = set_zero_pad(ctx, spec);
	ctx->digit_len = set_digit_len(*ctx);
	ctx->pad.space = set_space_pad(spec, *ctx);
	ctx->output_len = ctx->pad.space + ctx->digit_len;
	return (0);
}

static char	set_ptr_sign(t_spec spec)
{
	if (spec.flag & SIGNED)
		return ('+');
	if (spec.flag & BLANK_POS)
		return (' ');
	return (0);
}

static char	*set_ptr(t_arg arg)
{
	if (!arg.p)
		return ("(nil)");
	return (ptox((uintptr_t)arg.p));
}

// #include <stdio.h>
// int main(void)
// {
// 	// t_dec_ctx ctx;
// 	t_arg arg;
// 	arg.p = "a";
// 	t_spec spec;
// 	spec.flag = 127;
// 	spec.prec = 20;
// 	spec.width = 30;
// 	spec.type = PTR;
// 	int rev = print_ptr(arg, spec);
// 	printf("\nreturn value: %d\n", rev);
// 	int rev2 = printf("%-#+30.20p", arg.p);
// 	printf("\nreturn value: %d\n", rev2);
// }