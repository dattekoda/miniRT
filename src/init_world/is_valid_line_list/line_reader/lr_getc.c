/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lr_getc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:18:24 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/02 18:19:01 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_reader.h"

char	lr_getc(const t_line_reader *line_reader)
{
	return (line_reader->line[line_reader->idx]);
}
