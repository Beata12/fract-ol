/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarek <bmarek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 06:11:12 by bmarek            #+#    #+#             */
/*   Updated: 2024/03/22 08:18:23 by bmarek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static int	skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

static double	get_int_part(char *str, int *i)
{
	double	result;

	result = 0.0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10.0 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

static void	get_decimal_part(char *str, double *result, int *i)
{
	double	decimal;

	decimal = 0.1;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		(*result) = (*result) + (str[(*i)++] - '0') * decimal;
		decimal *= 0.1;
	}
	if (str[*i] != '\0')
	{
		my_error();
		error_dot_julia();
	}
}

double	ft_atod(char *str)
{
	int		i;
	int		sign;
	double	result;
	double	decimal;

	sign = 1;
	decimal = 0.1;
	i = skip_spaces(str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		if (!is_number(str[++i]))
			error_dot_julia();
	}
	result = get_int_part(str, &i);
	if (str[i] == '.')
	{
		if (!is_number(str[++i]))
			error_dot_julia();
		get_decimal_part(str, &result, &i);
	}
	return (result *= sign);
}
