/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:35:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/10/03 10:49:33 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_output.h"
#include "libft.h"

static void	set_char_ctx(t_ctx *ctx, t_arg arg, t_spec spec);

int	print_char(t_arg arg, t_spec spec)
{
	t_ctx	ctx;

	ft_bzero(&ctx, sizeof(ctx));
	set_char_ctx(&ctx, arg, spec);
	if (output(ctx, spec) == ERROR)
		return (ERROR);
	return (ctx.output_len);
}

static void	set_char_ctx(t_ctx *ctx, t_arg arg, t_spec spec)
{
	ctx->val = (char)arg.i;
	ctx->sign = 0;
	ctx->prefix = NULL;
	ctx->base_str = (char *)&ctx->val;
	ctx->base_len = 1;
	ctx->pad.zero = 0;
	ctx->digit_len = ctx->base_len;
	ctx->pad.space = set_space_pad(spec, *ctx);
	ctx->output_len = ctx->pad.space + ctx->digit_len;
}

// #include <stdio.h>
// int main(void)
// {
// 	// t_dec_ctx ctx;
// 	t_arg arg;
// 	arg.i = 'X';
// 	t_spec spec;
// 	spec.flag = 0;
// 	spec.prec = DEFAULT;
// 	spec.width = DEFAULT;
// 	spec.type = DEC;
// 	//init_dec_ctx(&ctx, arg, spec);
// 	//printf("val: %ld, sign: %c, num_str: %s", ctx.val, ctx.sign, ctx.num_str);
// 	int rev = print_char(arg, spec);
// 	printf("\nreturn value: %d\n", rev);
// }