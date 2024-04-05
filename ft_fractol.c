/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarek <bmarek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 05:01:32 by bmarek            #+#    #+#             */
/*   Updated: 2024/03/23 07:13:59 by bmarek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc == 2)
	{
		if (!ft_strcmp(argv[1], "mandelbrot"))
		{
			init_graphic_env(&fractal, argv[1]);
			draw_mandelbrot(&fractal);
		}
		else if (!ft_strcmp(argv[1], "julia"))
		{
			init_graphic_env(&fractal, argv[1]);
			draw_julia(&fractal);
		}
	}
	if (argc == 4 && !ft_strcmp(argv[1], "julia"))
	{
		if (check_valid_argument(argv[2]) && check_valid_argument(argv[3]))
			check_args_and_draw_julia(&fractal, argv[1], argv[2], argv[3]);
	}
	else
		return_error();
	return (0);
}
