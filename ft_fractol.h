/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarek <bmarek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 05:31:15 by bmarek            #+#    #+#             */
/*   Updated: 2024/03/23 12:03:21 by bmarek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include <limits.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_fractal
{
	int		bpp;
	int		line_length;
	int		byte_order;
	int		color;
	int		iterator;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx;
	char	*fractal_type;
	void	*img;
	char	*addr;
	double	x;
	double	y;
	double	curr_pos_x;
	double	curr_pos_y;
	double	start_x;
	double	start_y;
	double	end_x;
	double	end_y;
	double	x_real;
	double	y_imag;
	double	x_temp;
	double	y_temp;
	double	zoom;
	int		flag;

}	t_fractal;

double	ft_atod(char *str);

int		check_valid_argument(char *str);
int		close_x_button(t_fractal *fractal);
int		handle_mouse_zoom(int mouse_scroll_direction, int x,
			int y, t_fractal *fractal);
int		is_number(char c);
int		ft_strcmp(char *s1, char *s2);
int		key_hook_julia(int keycode, t_fractal *fractal);
int		key_hook_mandel(int keycode, t_fractal *fractal);
int		set_julia(t_fractal *fractal);
int		set_mandelbrot(t_fractal *fractal);

size_t	ft_strlen(const char *s);

void	assign_color(t_fractal *fractal);
void	calculate_julia_coordinates(t_fractal *fractal);
void	calculate_mandelbrot_coordinates(t_fractal *fractal);
void	check_args_and_draw_julia(t_fractal *fracal,
			char *fractal_name, char *num1, char *num2);
void	draw_julia(t_fractal *fractal);
void	draw_mandelbrot(t_fractal *fractal);
void	error_julia(void);
void	error_dot_julia(void);
void	error_mandelbort(void);
void	init_graphic_env(t_fractal *fractal, char *fractal_type);
void	my_error(void);
void	return_error(void);

#endif