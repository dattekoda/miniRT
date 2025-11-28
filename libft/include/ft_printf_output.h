/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:38:39 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/12 14:47:01 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_OUTPUT_H
# define FT_PRINTF_OUTPUT_H

# include "ft_printf_format.h"
# include <unistd.h>
// pads struct
typedef struct s_pad
{
	long	zero;
	long	space;
}	t_pad;

typedef struct s_context
{
	long	val;
	char	sign;
	char	*prefix;
	char	*base_str;
	long	base_len;
	long	digit_len;
	t_pad	pad;
	long	output_len;
}	t_ctx;

// print vargs
int		print_char(t_arg arg, t_spec spec);
int		print_dec(t_arg arg, t_spec spec);
int		print_u_int(t_arg arg, t_spec spec);
int		print_hex(t_arg arg, t_spec spec);
int		print_str(t_arg arg, t_spec spec);
int		print_ptr(t_arg arg, t_spec spec);
int		print_percent(void);
char	set_sign_abs(long *val, int flag);
long	set_zero_pad(t_ctx *ctx, t_spec spec);
long	set_space_pad(t_spec spec, t_ctx ctx);
long	set_digit_len(t_ctx ctx);

char	*ltox(long n, int is_upper);
char	*ptox(uintptr_t p);
int		pad_char(char c, int len);
int		output(t_ctx ctx, t_spec spec);
int		ft_putstr_safe(char *s);
int		ft_putchar_safe(char c);
size_t	ft_strnlen(const char *s, size_t maxlen);
char	*ft_ltoa(long n);

#endif