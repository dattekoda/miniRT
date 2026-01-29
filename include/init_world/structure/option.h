/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 02:39:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/28 20:47:13 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTION_H
# define OPTION_H

enum e_option
{
	OPT_ARTIFICIAL = (1 << 0),
	OPT_MATERIAL = (1 << 1),
	OPT_PPM = (1 << 2),
};

typedef struct s_option
{
	char			*str;
	enum e_option	flag;
}	t_option;

#endif
