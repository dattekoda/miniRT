/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 06:44:46 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/17 06:03:06 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_output.h>

static int	output_left_aligned(t_ctx ctx);
static int	output_right_aligned(t_ctx ctx);

int	output(t_ctx ctx, t_spec spec)
{
	if (spec.flag & LEFT_JUST)
	{
		if (output_left_aligned(ctx) == ERROR)
			return (ERROR);
	}
	else
		if (output_right_aligned(ctx) == ERROR)
			return (ERROR);
	return (0);
}

static int	output_left_aligned(t_ctx ctx)
{
	if (ctx.sign)
		if (write(1, &ctx.sign, 1) == -1)
			return (ERROR);
	if (ctx.val != 0)
	{
		if (ft_putstr_safe(ctx.prefix) == -1)
			return (ERROR);
	}
	if (pad_char('0', ctx.pad.zero) == -1)
		return (ERROR);
	if (write(1, ctx.base_str, ctx.base_len) == -1)
		return (ERROR);
	if (pad_char(' ', ctx.pad.space) == -1)
		return (ERROR);
	return (0);
}

static int	output_right_aligned(t_ctx ctx)
{
	if (pad_char(' ', ctx.pad.space) == -1)
		return (ERROR);
	if (ctx.sign)
		if (write(1, &ctx.sign, 1) == -1)
			return (ERROR);
	if (ctx.val != 0)
	{
		if (ft_putstr_safe(ctx.prefix) == -1)
			return (ERROR);
	}
	if (pad_char('0', ctx.pad.zero) == -1)
		return (ERROR);
	if (write(1, ctx.base_str, ctx.base_len) == -1)
		return (ERROR);
	return (0);
}

int	ft_putstr_safe(char *s)
{
	if (!s)
		return (0);
	if (write(1, s, ft_strlen(s)) == -1)
		return (-1);
	return (0);
}
