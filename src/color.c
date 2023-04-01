/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:13:22 by bhennequ          #+#    #+#             */
/*   Updated: 2023/03/30 16:04:10 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <math.h>

void	color(t_data *data, int color, int x, int y)
{
	char	*tmp;

	tmp = (data->addr + (y * data->line_length + x * 4));
	*(unsigned int *)tmp = color;
}
