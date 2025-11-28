/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:40:09 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/10/03 10:49:00 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_output.h"
#include "libft.h"

static void	set_str_ctx(t_ctx *ctx, t_arg arg, t_spec spec);
static char	*set_str(t_arg arg, t_spec spec);

int	print_str(t_arg arg, t_spec spec)
{
	t_ctx	ctx;

	ft_bzero(&ctx, sizeof(ctx));
	set_str_ctx(&ctx, arg, spec);
	if (output(ctx, spec) == ERROR)
		return (ERROR);
	return (ctx.output_len);
}

static void	set_str_ctx(t_ctx *ctx, t_arg arg, t_spec spec)
{
	ctx->val = 0;
	ctx->sign = 0;
	ctx->prefix = NULL;
	ctx->base_str = (char *)set_str(arg, spec);
	ctx->base_len = ft_strnlen(ctx->base_str, spec.prec);
	ctx->pad.zero = 0;
	ctx->digit_len = ctx->base_len;
	ctx->pad.space = set_space_pad(spec, *ctx);
	ctx->output_len = ctx->pad.space + ctx->digit_len;
}

static char	*set_str(t_arg arg, t_spec spec)
{
	if (!arg.p)
	{
		if ((size_t)spec.prec < ft_strlen("(null)"))
			return ("");
		else
			return ("(null)");
	}
	return ((char *)arg.p);
}

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	if (len > maxlen)
		len = maxlen;
	return (len);
}

// #include <stdio.h>
// int main(void)
// {
// 	// t_dec_ctx ctx;
// 	t_arg arg;
// 	arg.p = "hello\n";
// 	t_spec spec;
// 	spec.flag = 0;
// 	spec.prec = 3;
// 	spec.width = 20;
// 	//int rev = print_str(arg, spec);
// 	// int rev = printf("%020.3p\n", (char *)arg.p);
// 	// printf("return value: %d\n", rev);
// 	int rev = print_str(arg, spec);
// 	printf("\nreturn value: %d\n", rev);
// 	int rev2 = printf("%20.3s", (char *)arg.p);
// 	printf("\nreturn value: %d\n", rev2);
// }