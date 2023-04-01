/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:09:47 by bhennequ          #+#    #+#             */
/*   Updated: 2023/03/31 21:54:27 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <math.h>
void    init_burning_ship(t_data *vars)
{
    vars->type_fract = 4;
    vars->max_iter = 100;
    vars->zoom = 300;
    vars->x_set = -2;
    vars->y_set = -2;
}

void    calcul_burning_ship(t_data *data, t_complex c, int x, int y)
{
    t_complex   z;
    int         i;
	t_complex	tmp;

    z.re = 0;
    z.im = 0;
    i = 0;
    while (i < data->max_iter)
    {
        tmp.re = z.re * z.re - z.im * z.im + c.re;
        tmp.im = 2 * fabs(z.re * z.im) + c.im;
        z = tmp;
        if (z.re * z.re + z.im * z.im > 4)
            break ;
        i++;
    }
    if (i == data->max_iter)
        color(data, 0, x, y);
    else
        color(data, data->color & ~data->mask * i, x, y);
}

void    render_burning_ship(t_data *data)
{
    t_complex   c;
    int         x;
    int         y;

    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
            &data->line_length, &data->endian);
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            c.re = (x / data->zoom + data->x_set);
            c.im = -(y / data->zoom + data->y_set);
            calcul_burning_ship(data, c, x, y);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    mlx_destroy_image(data->mlx, data->img);
}
