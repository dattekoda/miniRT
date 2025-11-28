/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:25:36 by khanadat          #+#    #+#             */
/*   Updated: 2025/11/28 15:19:42 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_UTILS_H
# define VALIDATE_UTILS_H

// validate_ambient.c
int	validate_ambient(char *line_ptr);

// validate_camera.c

// validate_utils.c
int	skip_spaces(char **ptr);
int	skip_digit(char **ptr);

#endif