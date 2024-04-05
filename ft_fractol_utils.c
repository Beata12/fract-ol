/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarek <bmarek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 05:15:12 by bmarek            #+#    #+#             */
/*   Updated: 2024/03/23 11:54:05 by bmarek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	mlx_put_image_to_wimdow(t_fractal *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	my_mlx_pixel_put(t_fractal *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	assign_color(t_fractal *fractal)
{
	int	red;
	int	green;
	int	blue;

	if (fractal->iterator == -1)
	{
		my_mlx_pixel_put(fractal, fractal->curr_pos_x,
			fractal->curr_pos_y, 0xFFF);
	}
	else
	{
		red = (fractal->iterator * 8) % 256;
		green = (fractal->iterator * 33) % 256;
		blue = (fractal->iterator * 12) % 256;
		fractal->color = (red << 16) | (green << 8) | blue;
		mlx_put_image_to_wimdow(fractal, fractal->curr_pos_x,
			fractal->curr_pos_y, fractal->color);
	}
}
