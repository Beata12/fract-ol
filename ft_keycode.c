/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarek <bmarek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 08:26:44 by bmarek            #+#    #+#             */
/*   Updated: 2024/03/23 11:53:32 by bmarek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static int	close_escape(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img);
	mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_win);
	exit(1);
	return (0);
}

int	close_x_button(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_win);
	exit(0);
	return (0);
}

int	key_hook_julia(int keycode, t_fractal *fractal)
{
	if (keycode == 65307)
		close_escape(fractal);
	else if (keycode == 65361)
	{
		fractal->start_x -= 0.01 / fractal->zoom;
		fractal->end_x -= 0.01 / fractal->zoom;
	}
	else if (keycode == 65363)
	{
		fractal->start_x += 0.01 / fractal->zoom;
		fractal->end_x += 0.01 / fractal->zoom;
	}
	else if (keycode == 65362)
	{
		fractal->start_y -= 0.01 / fractal->zoom;
		fractal->end_y -= 0.01 / fractal->zoom;
	}
	else if (keycode == 65364)
	{
		fractal->start_y += 0.01 / fractal->zoom;
		fractal->end_y += 0.01 / fractal->zoom;
	}
	draw_julia(fractal);
	return (0);
}

int	key_hook_mandel(int keycode, t_fractal *fractal)
{
	if (keycode == 65307)
		close_escape(fractal);
	else if (keycode == 65361)
	{
		fractal->start_x -= 0.1 / fractal->zoom;
		fractal->end_x -= 0.1 / fractal->zoom;
	}
	else if (keycode == 65363)
	{
		fractal->start_x += 0.1 / fractal->zoom;
		fractal->end_x += 0.1 / fractal->zoom;
	}
	else if (keycode == 65362)
	{
		fractal->start_y -= 0.1 / fractal->zoom;
		fractal->end_y -= 0.1 / fractal->zoom;
	}
	else if (keycode == 65364)
	{
		fractal->start_y += 0.1 / fractal->zoom;
		fractal->end_y += 0.1 / fractal->zoom;
	}
	draw_mandelbrot(fractal);
	return (0);
}
