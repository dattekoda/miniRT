/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:55:17 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/11/29 18:42:18 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef GNL_ERR_INVALID
#  define GNL_ERR_INVALID -3
# endif

# ifndef GNL_ERR_MALLOC
#  define GNL_ERR_MALLOC -2
# endif

# ifndef GNL_ERR_READ
#  define GNL_ERR_READ -1
# endif

# ifndef GNL_EOF
#  define GNL_EOF 0
# endif

# ifndef GNL_LINE
#  define GNL_LINE 1
# endif

int	ft_get_next_line(int fd, char **line);

#endif