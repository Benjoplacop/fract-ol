/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:57:35 by bhennequ          #+#    #+#             */
/*   Updated: 2023/03/31 20:28:08 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include "../fractol.h"
#include <stdio.h>

void	take_preset_julia(t_data *vars, double re, double im)
{
	init_julia(vars);
	vars->comp.re = re;
	vars->comp.im = im;
	vars->ultra_mode = 0;
	vars->ultra_mode2 = 0;
}

void	init_julia(t_data *vars)
{
	vars->type_fract = 1;
	vars->max_iter = 100;
	vars->zoom = 350;
	vars->x_set = -1.6;
	vars->y_set = -1.8;
	vars->comp.re = 0.285;
	vars->comp.im = 0.01;
}

void	calcul_julia(t_data *data, t_complex z, int x, int y)
{
	t_complex	tmp;
	int			i;

	i = 0;
	while (i < data->max_iter)
	{
		tmp.re = z.re * z.re - z.im * z.im;
		tmp.im = 2 * z.re * z.im;
		z.re = tmp.re + data->comp.re;
		z.im = tmp.im + data->comp.im;
		if (z.re * z.re + z.im * z.im > 4)
			break ;
		i++;
	}
	if (i == data->max_iter)
		color(data, 0, x, y);
	else
		color(data, data->color & ~data->mask * i, x, y);
}

void	render_julia(t_data *data)
{
	t_complex	z;
	int			x;
	int			y;

	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z.re = (x / data->zoom + data->x_set);
			z.im = (y / data->zoom + data->y_set);
			calcul_julia(data, z, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
}
