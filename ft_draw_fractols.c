/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fractols.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarek <bmarek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 05:41:39 by bmarek            #+#    #+#             */
/*   Updated: 2024/03/23 08:52:54 by bmarek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	draw_julia(t_fractal *fractal)
{
	fractal->curr_pos_y = 0;
	while (fractal->curr_pos_y < HEIGHT)
	{
		fractal->curr_pos_x = 0;
		while (fractal->curr_pos_x < WIDTH)
		{
			calculate_julia_coordinates(fractal);
			fractal->color = set_julia(fractal);
			fractal->curr_pos_x++;
		}
		fractal->curr_pos_y++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->mlx_win,
		fractal->img, 0, 0);
	mlx_mouse_hook(fractal->mlx_win, &handle_mouse_zoom, fractal);
	mlx_key_hook(fractal->mlx_win, key_hook_julia, fractal);
	mlx_hook(fractal->mlx_win, 17, 0, &close_x_button, fractal);
	mlx_loop(fractal->mlx_ptr);
}

void	draw_mandelbrot(t_fractal *fractal)
{
	fractal->curr_pos_y = 0;
	while (fractal->curr_pos_y < HEIGHT)
	{
		fractal->curr_pos_x = 0;
		while (fractal->curr_pos_x < WIDTH)
		{
			calculate_mandelbrot_coordinates(fractal);
			fractal->color = set_mandelbrot(fractal);
			fractal->curr_pos_x++;
		}
		fractal->curr_pos_y++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->mlx_win,
		fractal->img, 0, 0);
	mlx_mouse_hook(fractal->mlx_win, &handle_mouse_zoom, fractal);
	mlx_key_hook(fractal->mlx_win, key_hook_mandel, fractal);
	mlx_hook(fractal->mlx_win, 17, 0, &close_x_button, fractal);
	mlx_loop(fractal->mlx_ptr);
}
