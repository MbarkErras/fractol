/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 08:06:07 by merras            #+#    #+#             */
/*   Updated: 2019/10/22 23:30:05 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_complex c, t_complex m)
{
	int			i;
	t_complex	z;
	double		temp;

	i = 0;
	z.re = c.re;
	z.im = c.im;
	while (i < MAX_ITERATIONS)
	{
		temp = z.re;
		z.re = z.re * z.re - z.im * z.im + m.re;
		z.im = 2 * z.im * temp + m.im;
		if (z.re * z.re + z.im * z.im >= 4)
			break ;
		i++;
	}
	return (i < MAX_ITERATIONS);
}
