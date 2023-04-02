/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:37:17 by bhennequ          #+#    #+#             */
/*   Updated: 2023/04/02 15:56:14 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include "../fractol.h"
#include <stdio.h>

static t_data	*ft_test_fractal(char **argv, t_data *vars)
{
	if (!ft_strncmp(argv[1], "Julia", 5))
	{
		if (!argv[2] || !argv[3])
		{	
			ft_putstr_fd("Need more arguments for Julia \n", 1);
			exit(0);
		}
		vars->comp.re = ft_atof(argv[2], vars);
		vars->comp.im = ft_atof(argv[3], vars);
		vars->type_fract = 1;
	}
	else if (!ft_strncmp(argv[1], "Mandelbrot", 10))
		vars->type_fract = 2;
	else if (!ft_strncmp(argv[1], "Burningship", 11))
		vars->type_fract = 3;
	else
		ft_error_put(vars);
	return (vars);
}

static void	init(t_data *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Fract-ol !");
	vars->color = 0x00FFFFFF;
	vars->mask = 0x00F0F0F0;
	vars->ultra_mode = 0;
	vars->y = 0;
	vars->x = 0;
	ft_put_tuto();
	print_fractol(vars);
}

int	mouse_motion(int x, int y, t_data *vars)
{
	if (vars->ultra_mode == 1)
	{
		mlx_mouse_get_pos(vars->mlx, vars->win, &x, &y);
		if (x != vars->x || y != vars->y)
		{
			vars->x = x;
			vars->y = y;
			vars->comp.re = (x - (double)WIDTH / 2) / vars->zoom;
			vars->comp.im = (y - (double)HEIGHT / 2) / vars->zoom;
			render_julia(vars);
		}
	}
}

int	main(int argc, char **argv)
{
	t_data	*vars;

	vars = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!vars)
		return (0);
	if (argc == 1)
		ft_error_put(vars);
	ft_test_fractal(argv, vars);
	init(vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_key_hook(vars->win, key_utils, vars);
	mlx_hook(vars->win, 17, 1L << 0, &destroy, vars);
	mlx_hook(vars->win, 6, 1L << 6, &mouse_motion, vars);
	mlx_loop(vars->mlx);
}
