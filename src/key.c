/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:16:47 by bhennequ          #+#    #+#             */
/*   Updated: 2023/03/31 20:15:27 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include "../fractol.h"

void	key_change_julia(int key, t_data *vars)
{
	if (key == 65436)
		take_preset_julia(vars, 0.285, 0.01);
	else if (key == 65433)
		take_preset_julia(vars, 0.3, 0.5);
	else if (key == 65435)
		take_preset_julia(vars, -1.4170222, 0.00995);
	else if (key == 65430)
		take_preset_julia(vars, -0.03808, 0.9754);
	else if (key == 65437)
		take_preset_julia(vars, -0.4, 0.6);
	else if (key == 65432)
		take_preset_julia(vars, -0.8, 0.156);
	else if (key == 65429)
		take_preset_julia(vars, -0.56, 0.395);
	else if (key == 65431)
		take_preset_julia(vars, -0.1011, 0.9563);
	else if (key == 65434)
		take_preset_julia(vars, -0.743643887037151, 0.13182590420533);
	else if (key == 65438)
	{	
		vars->ultra_mode = 1;
		vars->ultra_mode2 = 1;
		render_julia(vars);
	}
}

void	key_color(t_data *vars)
{
	if (vars->color == 0x00FFFFFF)
		vars->color = 0x00FF0000;
	else if (vars->color == 0x00FF0000)
		vars->color = 0x000000FF;
	else if (vars->color == 0x000000FF)
		vars->color = 0x00FFFF00;
	else if (vars->color == 0x00FFFF00)
		vars->color = 0x0000FF00;
	else if (vars->color == 0x0000FF00)
		vars->color = 0x0000FFFF;
	else if (vars->color == 0x0000FFFF)
		vars->color = 0x00FFFFFF;
}

int	key_utils(int key, t_data *vars)
{
	if (key == XK_Escape)
		destroy(vars);
	if (key == 32)
	{
		if (vars->type_fract == 2)
			init_julia(vars);
		else if (vars->type_fract == 1 && vars->ultra_mode == 0)
			init_mandel(vars);
	}
	if (vars->type_fract == 1)
		key_change_julia(key, vars);
	if (key == 65293)
		key_color(vars);
	if (key == 65361)
		vars->x_set = vars->x_set - 20 / vars->zoom;
	if (key == 65362)
		vars->y_set = vars->y_set - 20 / vars->zoom;
	if (key == 65364)
		vars->y_set = vars->y_set + 20 / vars->zoom;
	if (key == 65363)
		vars->x_set = vars->x_set + 20 / vars->zoom;
	print_zoom_fract(vars);
	return (0);
}
