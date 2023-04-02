/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:36:32 by bhennequ          #+#    #+#             */
/*   Updated: 2023/04/02 15:58:27 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"

static void	test_atof(const char *str, t_data *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '.')
			j++;
		i++;
	}
	if (j > 1)
	{
		ft_putstr_fd("Error too many '.' in arguments ", 1);
		free(vars);
		exit(0);
	}
}

double	ft_atof(const char *str, t_data *vars)
{
	double	res;
	double	res2;
	int		len;
	int		neg;

	test_atof(str, vars);
	neg = 1;
	if (*str == '-')
	{	
		str++;
		neg = -1;
	}
	res = (double)ft_atoi(str);
	while (*str && *str != '.')
		str++;
	if (*str == '.')
		str++;
	res2 = (double)ft_atoi(str);
	len = ft_strlen(str);
	while (len--)
		res2 = res2 / 10;
	if (neg == 1)
		return (res + res2);
	return ((res + res2) * neg);
}

void	ft_put_tuto(void)
{
	ft_putstr_fd("How to use:\n-Enter: Change color\n", 1);
	ft_putstr_fd("-Space: Change fractal\n", 1);
	ft_putstr_fd("-NUMPAD: You can change value of Julia (default: 1)\n", 1);
	ft_putstr_fd("-NUMPAD 0: Ultra mode for Julia (Enjoy !)\n", 1);
	ft_putstr_fd("-Arrow key: move on the fractal\n", 1);
	ft_putstr_fd("(\033[34mIn ultra mode you", 1);
	ft_putstr_fd(" can use left click for pause\033[0m)\n", 1);
}

void	ft_error_put(t_data *vars)
{
	ft_putstr_fd("\033[31mError Arguments\n", 1);
	ft_putstr_fd("\033[0mArguments available:\n", 1);
	ft_putstr_fd("\033[34m   -Mandelbrot\n\033[32m   -Julia\n", 1);
	ft_putstr_fd("\033[35m   -Burningship\n", 1);
	ft_putstr_fd("\033[0m(If you use Julia, give more params like: ", 1);
	ft_putstr_fd("./fractol Julia 0.285 0.01)\n", 1);
	free(vars);
	exit(0);
}

int	destroy(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	mlx_loop_end(data->mlx);
	free(data->mlx);
	free(data);
	exit(1);
	return (0);
}
