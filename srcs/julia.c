/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 08:06:07 by merras            #+#    #+#             */
/*   Updated: 2019/10/21 13:29:09 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_complex p, t_complex c)
{
	int			i;
	t_complex	z;
	double		temp;

	i = 0;
	z.re = 0;
	z.im = 0;
	while (i < MAX_ITERATIONS)
	{
		temp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.im * temp + c.im;
		if (z.re * z.re + z.im * z.im >= 4)
			break ;
		i++;
	}
	return (i < MAX_ITERATIONS);
}
