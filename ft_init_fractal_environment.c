/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fractal_environment.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarek <bmarek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 06:41:52 by bmarek            #+#    #+#             */
/*   Updated: 2024/03/23 08:16:50 by bmarek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void	init_fractal_variables(t_fractal *fractal, char *fractal_type)
{
	if (!ft_strcmp(fractal_type, "mandelbrot"))
	{
		fractal->start_x = -2;
		fractal->end_x = 0.9;
		fractal->start_y = -1.5;
		fractal->end_y = 1.5;
		fractal->zoom = 1.1;
	}
	else if (!ft_strcmp(fractal_type, "julia"))
	{
		fractal->start_x = -2.5;
		fractal->end_x = 2.5;
		fractal->start_y = -2.5;
		fractal->end_y = 2.5;
		fractal->zoom = 1.1;
		fractal->x_real = 0.285;
		fractal->y_imag = 0.01;
	}
}

void	init_graphic_env(t_fractal *fractal, char *fractal_type)
{
	fractal->mlx_ptr = mlx_init();
	if (fractal->mlx_ptr == NULL)
		my_error();
	fractal->mlx_win = mlx_new_window(fractal->mlx_ptr,
			WIDTH, HEIGHT, fractal_type);
	if (fractal->mlx_win == NULL)
		my_error();
	fractal->img = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (fractal->img == NULL)
		my_error();
	fractal->addr = mlx_get_data_addr(fractal->img, &(fractal->bpp),
			&(fractal->line_length), &(fractal->byte_order));
	fractal->fractal_type = fractal_type;
	init_fractal_variables(fractal, fractal_type);
}

int	handle_mouse_zoom(int mouse_scroll_direction,
					int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (mouse_scroll_direction == 4)
	{
		fractal->start_x *= fractal->zoom;
		fractal->end_x *= fractal->zoom;
		fractal->start_y *= fractal->zoom;
		fractal->end_y *= fractal->zoom;
	}
	else if (mouse_scroll_direction == 5)
	{
		fractal->start_x /= fractal->zoom;
		fractal->end_x /= fractal->zoom;
		fractal->start_y /= fractal->zoom;
		fractal->end_y /= fractal->zoom;
	}
	if (!ft_strcmp(fractal->fractal_type, "julia"))
		draw_julia(fractal);
	else
		draw_mandelbrot(fractal);
	return (0);
}
