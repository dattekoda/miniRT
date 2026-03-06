/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:28:54 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/06 11:28:09 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	mini_rt(int argc, char *argv[]);

#include "rt_debug.h"
int	main(int argc, char *argv[])
{
	init_time();
	return (mini_rt(argc, argv));
}
