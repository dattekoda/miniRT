/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:24:59 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/08 11:25:55 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

# define GNL_FREE_FD -4
# define GNL_ERR_INVALID -3
# define GNL_ERR_MALLOC -2
# define GNL_ERR_READ -1
# define GNL_EOF 0
# define GNL_LINE 1

typedef struct s_gnl
{
	char		*str;
	size_t		head;
	size_t		tail;
}	t_gnl;

#endif
