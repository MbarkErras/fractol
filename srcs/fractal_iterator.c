/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 08:06:07 by merras            #+#    #+#             */
/*   Updated: 2019/10/24 01:05:57 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractal_iterator(t_complex c, t_complex m, void *r)
{
	int			i;
	t_complex	z;
	double		temp;

	i = 0;
	z.re = R(fractal) != JULI ? 0 : c.re;
	z.im = R(fractal) != JULI ? 0 : c.im;
	while (i < MAX_ITERATIONS)
	{
		temp = z.re;
		z.re = (R(fractal) == CUBE ? z.re * z.re * z.re - 3 * z.re * z.im * z.im
		: z.re * z.re - z.im * z.im) + (R(fractal) == JULI ? m.re : c.re);
		z.im = (R(fractal) == CUBE ? 3 * z.im * temp * temp - z.im * z.im * z.im
		: 2 * z.im * temp) + (R(fractal) == JULI ? m.im : c.im);
		if (z.re * z.re + z.im * z.im >= 2)
			break ;
		i++;
	}
	return (MAX_ITERATIONS < 5 ? 0 : i / (MAX_ITERATIONS / 5));
}
