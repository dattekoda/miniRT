/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_element.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:58:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/16 18:59:14 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_TO_ELEMENT_H
# define LINE_TO_ELEMENT_H

#include "hitter.h"

int	line_to_light(t_hitter **light, const char *line);
int	line_to_sphere(t_hitter **sphere, const char *line);

#endif
