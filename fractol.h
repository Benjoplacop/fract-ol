/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:51:20 by bhennequ          #+#    #+#             */
/*   Updated: 2023/03/31 21:51:16 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1200
# define HEIGHT 1200

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			max_iter;
	int			color;
	int			mask;
	t_complex	comp;
	double		zoom;
	double		x_set;
	double		y_set;
	int			type_fract;
	int			ultra_mode;
	int			ultra_mode2;
	int			x;
	int			y;
}				t_data;

void	ft_put_tuto(void);
void	color(t_data *data, int color, int x, int y);
void	init_burning_ship(t_data *vars);
void	calcul_burning_ship(t_data *data, t_complex z, int x, int y);
void	render_burning_ship(t_data *data);
void	key_change_julia(int key, t_data *vars);
void	print_zoom_fract(t_data *vars);
int		key_utils(int key, t_data *vars);
void	take_preset_julia(t_data *vars, double re, double im);
void	print_fractol(t_data *vars);
int		mouse_hook(int button, int x, int y, t_data *vars);
void	init_julia(t_data *vars);
void	init_mandel(t_data *vars);
void	zoom_frac(int x, int y, t_data *vars);
void	unzoom_frac(int x, int y, t_data *vars);
int		destroy(t_data *data);
void	ft_error_put(t_data *vars);
double	ft_atof(const char *str, t_data *vars);
void	calcul_julia(t_data *data, t_complex z, int x, int y);
void	render_julia(t_data *param);
void	calcul_mandelbrot(t_data *data, int x, int y);
void	render_mandelbrot(t_data *data);
#endif
