/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarek <bmarek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 05:18:32 by bmarek            #+#    #+#             */
/*   Updated: 2024/03/23 12:03:14 by bmarek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void	check_double_dot(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			flag++;
		}
		i++;
	}
	if (flag > 1)
	{
		my_error();
		error_dot_julia();
		exit(1);
	}
}

void	check_args_and_draw_julia(t_fractal *fractal,
		char *fractal_name, char *num1, char *num2)
{
	fractal->fractal_type = fractal_name;
	check_double_dot(num1);
	check_double_dot(num2);
	init_graphic_env(fractal, fractal->fractal_type);
	fractal->y_imag = ft_atod(num2);
	fractal->x_real = ft_atod(num1);
	draw_julia(fractal);
}

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_valid_argument(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= 'a' && str[i] <= 'z'))
		{
			my_error();
			error_julia();
			exit (1);
		}
		else if (is_number(str[i]))
			i++;
		else if (str[i] == '+')
			i++;
		else if (str[i] == '-')
			i++;
		else if (str[i] == '.')
			i++;
		else if (str[i] == ' ')
			i++;
	}
	return (1);
}
