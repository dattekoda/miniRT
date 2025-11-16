/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:25:36 by khanadat          #+#    #+#             */
/*   Updated: 2025/11/16 14:40:05 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_UTILS_H
# define VALIDATE_UTILS_H

int	validate_ambient(char *line);

int	skip_spaces(char **line);
int	skip_digit(char **line);

#endif