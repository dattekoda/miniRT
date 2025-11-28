/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 01:02:44 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/05/11 01:14:25 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_format.h"

void	pop_varg(t_arg *arg, int type, va_list ap)
{
	if (type == CHAR)
		arg->i = va_arg(ap, int);
	else if (type == DEC)
		arg->i = va_arg(ap, int);
	else if (type == U_INT)
		arg->u = va_arg(ap, unsigned int);
	else if (type == HEX_LOW)
		arg->u = va_arg(ap, unsigned int);
	else if (type == HEX_UP)
		arg->u = va_arg(ap, unsigned int);
	else if (type == STR)
		arg->p = va_arg(ap, void *);
	else if (type == PTR)
		arg->p = va_arg(ap, void *);
}

// #include <stdio.h>
// void	put_varg(int type, ...);
// int main(void)
// {
// 	int		vd = 10;
// 	char	vc = 'A';
// 	char	*vs = "abcdef";
// 	put_varg(DEC, vd);
// 	put_varg(CHAR, vc);
// 	put_varg(STR, vs);
// }

// void	put_varg(int type, ...)
// {
// 	t_arg arg;
// 	va_list ap;
// 	va_start(ap, type);
// 	pop_arg(&arg, type, ap);
// 	if (type == DEC)
// 		printf("DEC: %d\n", arg.i);
// 	else if (type == CHAR)
// 		printf("CHAR: %c\n", (char)arg.i);
// 	else if (type == U_INT)
// 		printf("U_INT: %u\n", arg.u);
// 	else if (type == STR)
// 		printf("STR: %s\n", (char *)arg.p);
// 	va_end(ap);
// }