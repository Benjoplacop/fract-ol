/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:35:12 by bhennequ          #+#    #+#             */
/*   Updated: 2023/03/31 20:34:53 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include "../fractol.h"
#include <math.h>

void	init_mandel(t_data *vars)
{
	vars->type_fract = 2;
	vars->max_iter = 100;
	vars->zoom = 300;
	vars->x_set = -2.4;
	vars->y_set = -2;
}

void	calcul_mandelbrot(t_data *data, int x, int y)
{
	t_complex	tmp;
	int			i;
	t_complex	z;

	z.im = 0;
	z.re = 0;
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

void	render_mandelbrot(t_data *data)
{
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
			data->comp.re = x / data->zoom + data->x_set;
			data->comp.im = -(y / data->zoom + data->y_set);
			calcul_mandelbrot(data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
}
