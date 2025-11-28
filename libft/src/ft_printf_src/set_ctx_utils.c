/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ctx_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:22:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/12 20:09:03 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_output.h"

static int	is_zero_flag_valid(t_spec spec);

char	set_sign_abs(long *val, int flag)
{
	char	sign;

	sign = 0;
	if (*val < 0)
	{
		sign = '-';
		*val = -(*val);
	}
	else if (flag & SIGNED)
		sign = '+';
	else if (flag & BLANK_POS)
		sign = ' ';
	return (sign);
}

long	set_zero_pad(t_ctx *ctx, t_spec spec)
{
	if (is_zero_flag_valid(spec))
	{
		ctx->digit_len = ctx->base_len + !!ctx->sign + ft_strlen(ctx->prefix);
		if (spec.width > ctx->digit_len)
			return (spec.width - ctx->digit_len);
	}
	else
	{
		if (spec.prec == 0 && ctx->val == 0)
		{
			ctx->base_str[0] = '\0';
			ctx->base_len = 0;
			ctx->sign = 0;
		}
		if (spec.prec > ctx->base_len)
			return (spec.prec - ctx->base_len);
	}
	return (0);
}

static int	is_zero_flag_valid(t_spec spec)
{
	if (!(spec.flag & ZERO_PADD))
		return (0);
	if (spec.prec != DEFAULT)
		return (0);
	if (spec.flag & LEFT_JUST)
		return (0);
	return (1);
}

long	set_space_pad(t_spec spec, t_ctx ctx)
{
	if (!is_zero_flag_valid(spec))
		if (spec.width > ctx.digit_len)
			return (spec.width - ctx.digit_len);
	return (0);
}

long	set_digit_len(t_ctx ctx)
{
	long	len;

	len = 0;
	len += !!ctx.sign;
	len += ft_strlen(ctx.prefix) * (!!ctx.val);
	len += ctx.pad.zero;
	len += ctx.base_len;
	return (len);
}
