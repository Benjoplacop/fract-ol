/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:37:28 by bhennequ          #+#    #+#             */
/*   Updated: 2023/03/31 21:50:34 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"

void	print_fractol(t_data *vars)
{
	if (vars->type_fract == 1 && vars->ultra_mode == 0)
	{
		take_preset_julia(vars, vars->comp.re, vars->comp.im);
		render_julia(vars);
	}
	else if (vars->type_fract == 2)
	{
		init_mandel(vars);
		render_mandelbrot(vars);
	}
	else if (vars->type_fract == 3)
	{
		init_burning_ship(vars);
		render_burning_ship(vars);
	}
}

void	print_zoom_fract(t_data *vars)
{
	if (vars->type_fract == 1)
		render_julia(vars);
	else if (vars->type_fract == 2)
		render_mandelbrot(vars);
	else
		render_burning_ship(vars);
}

int	mouse_hook(int button, int x, int y, t_data *vars)
{
	if (button == 4)
		zoom_frac(x, y, vars);
	else if (button == 5)
		unzoom_frac(x, y, vars);
	else if (button == 1)
	{
		if (vars->ultra_mode == 0 && vars->ultra_mode2 == 1)
			vars->ultra_mode = 1;
		else
			vars->ultra_mode = 0;
	}
	print_zoom_fract(vars);
	return (0);
}

void	zoom_frac(int x, int y, t_data *vars)
{
	vars->x_set = (x / vars->zoom + vars->x_set) - (x / (vars->zoom * 1.25));
	vars->y_set = (y / vars->zoom + vars->y_set) - (y / (vars->zoom * 1.25));
	vars->zoom = vars->zoom * 1.25;
}

void	unzoom_frac(int x, int y, t_data *vars)
{
	vars->x_set = (x / vars->zoom + vars->x_set) - (x / (vars->zoom / 1.25));
	vars->y_set = (y / vars->zoom + vars->y_set) - (y / (vars->zoom / 1.25));
	vars->zoom = vars->zoom / 1.25;
}
