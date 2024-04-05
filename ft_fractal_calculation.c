/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_calculation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarek <bmarek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:01:05 by bmarek            #+#    #+#             */
/*   Updated: 2024/03/23 12:10:18 by bmarek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	calculate_mandelbrot_coordinates(t_fractal *fractal)
{
	fractal->x = fractal->curr_pos_x *((fractal->end_x
				- fractal->start_x) / WIDTH) + fractal->start_x;
	fractal->y = fractal->curr_pos_y * ((fractal->end_y
				- fractal->start_y) / HEIGHT) + fractal->start_y;
	fractal->x_real = fractal->x;
	fractal->y_imag = fractal->y;
}

void	calculate_julia_coordinates(t_fractal *fractal)
{
	fractal->x = fractal->curr_pos_x * ((fractal->end_x
				- fractal->start_x) / WIDTH) + fractal->start_x;
	fractal->y = fractal->curr_pos_y * ((fractal->end_y
				- fractal->start_y) / HEIGHT) + fractal->start_y;
}

int	set_julia(t_fractal *fractal)
{
	fractal->iterator = 0;
	while (fractal->iterator < 100)
	{
		fractal->x_temp = fractal->x * fractal->x - fractal->y * fractal->y
			+ fractal->x_real;
		fractal->y_temp = 2 * fractal->x * fractal->y + fractal->y_imag;
		fractal->x = fractal->x_temp;
		fractal->y = fractal->y_temp;
		fractal->iterator++;
		if (fractal->x * fractal->x + fractal->y * fractal->y > 20)
			break ;
	}
	if (fractal->iterator == 30)
		fractal->iterator = -1;
	assign_color(fractal);
	return (fractal->iterator);
}

int	set_mandelbrot(t_fractal *fractal)
{
	fractal->x = 0.0;
	fractal->y = 0.0;
	fractal->iterator = 0;
	while (fractal->iterator < 60)
	{
		fractal->x_temp = (fractal->x * fractal->x) - (fractal->y * fractal->y)
			+ fractal->x_real;
		fractal->y_temp = (2 * fractal->x * fractal->y) + fractal->y_imag;
		fractal->x = fractal->x_temp;
		fractal->y = fractal->y_temp;
		fractal->iterator++;
		if (fractal->x * fractal->x + fractal->y * fractal->y > 20)
			break ;
	}
	if (fractal->iterator == 30)
		fractal->iterator = -1;
	assign_color(fractal);
	return (fractal->iterator);
}
