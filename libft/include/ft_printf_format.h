/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:13:08 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/11 08:10:37 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FORMAT_H
# define FT_PRINTF_FORMAT_H

# include "ft_printf.h"
# include <stdlib.h>
// flug const number
# define ALT_FORM	0b00000001 // '#'
# define BLANK_POS	0b00000010 // ' '
# define SIGNED		0b00000100 // '+'
# define LEFT_JUST	0b00001000 // '-
# define ZERO_PADD	0b00010000 // '0'
# define WIDTH_ARG	0b00100000 // '*'
# define PREC_ARG	0b01000000 // '.*'
// type const number
# define CHAR		1
# define DEC		2
# define U_INT		3
# define HEX_LOW	4
# define HEX_UP		5
# define STR		6
# define PTR		7
# define PERCENT	8
// arg union
typedef union u_arg
{
	int				i;
	unsigned int	u;
	void			*p;
}	t_arg;
// fomrat spec struct
typedef struct s_spec
{
	int	flag;
	int	width;
	int	prec;
	int	type;
}	t_spec;
// get format spec
void	get_format_spec(const char **fmt, t_spec *spec);
// pop vargs
void	pop_varg(t_arg *arg, int type, va_list ap);
// output varg
int		print_arg(t_arg arg, t_spec spec);
#endif 