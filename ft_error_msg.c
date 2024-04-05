/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarek <bmarek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 05:18:32 by bmarek            #+#    #+#             */
/*   Updated: 2024/03/22 08:33:53 by bmarek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	my_error(void)
{
	const char	*usage_msg;

	usage_msg = "\033[31m\n❗ ❗ ❗	E	R	R	O	R	❗ ❗ ❗\033[0m\n\n";
	write(2, usage_msg, ft_strlen(usage_msg));
}

void	error_julia(void)
{
	const char	*julia_msg;
	const char	*error_msg;
	const char	*num_msg;

	julia_msg = "\033[31mJulia set:			";
	error_msg = "\033[33m./fractol julia ";
	num_msg = "\e[1;93m<num_1> <num_2>\033[0m\n";
	write(2, julia_msg, ft_strlen(julia_msg));
	write(2, error_msg, ft_strlen(error_msg));
	write(1, "\n", 1);
	write(2, julia_msg, ft_strlen(julia_msg));
	write(2, error_msg, ft_strlen(error_msg));
	write(2, num_msg, ft_strlen(num_msg));
}

void	error_dot_julia(void)
{
	const char	*julia_msg;
	const char	*error_msg;
	const char	*num_msg;

	julia_msg = "\033[31m	Julia set:	";
	error_msg = "\033[33m./fractol julia ";
	num_msg = "\e[1;93m-0.79 0.15 \033[0m\n";
	write(2, julia_msg, ft_strlen(julia_msg));
	write(2, error_msg, ft_strlen(error_msg));
	write(2, num_msg, ft_strlen(num_msg));
}

void	error_mandelbort(void)
{
	const char	*mandelbort_msg;
	const char	*error_msg;

	mandelbort_msg = "\033[31mMandelbrot set:			";
	error_msg = "\033[33m./fractol mandelbrot\033[0m\n\033[0m";
	write(2, mandelbort_msg, ft_strlen(mandelbort_msg));
	write(2, error_msg, ft_strlen(error_msg));
}

void	return_error(void)
{
	my_error();
	error_julia();
	error_mandelbort();
}
