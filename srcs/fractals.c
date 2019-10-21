/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 23:05:37 by merras            #+#    #+#             */
/*   Updated: 2019/06/26 03:28:23 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		convergence(double re, double im)
{
	int			i;
	long double	temp;
	t_complex	z;
	t_complex	c;

	c.r = re;
	c.i = im;

	z.r = 0;
	z.i = 0;

	i = 0;
	while (distance(z.r, z.i) < 4 && i < MAX_ITER)
	{
		temp = z.r;
		z.r = z.r * z.r + c.r - z.i * z.i;
		z.i = 2 * temp * z.i + c.i;
		i++;
	}
	return (i == MAX_ITER ? 1 : 0);
}

t_xy	init_renderer(int fractol)
{
	t_xy		xy_conf;

	xy_conf.height = WIDTH;
	xy_conf.width = HEIGHT;
	xy_conf.fractol = fractol;

	xy_conf.gserver = mlx_init();
	xy_conf.win = mlx_new_window(xy_conf.gserver, xy_conf.width, xy_conf.height, "fractol");

	xy_conf.r_max = INIT_XY;
	xy_conf.r_min = -INIT_XY;
	xy_conf.i_max = INIT_XY;
	xy_conf.i_min = -INIT_XY; 

	return (xy_conf);	
}

int		rerender_handler(int button, int x, int y, t_xy *xy)
{
	if (xy->fractol == MANDELBROT)
	 	mandelbrot_render_handler(button, x, y, xy);
	/*if (xy->fractol == JULIA)
	 	julia_renderer(button, x, y, xy);
	if (xy->fractol == TREE_INDEX)
	 	tree_index_renderer(button, x, y, xy);*/
	return (0);
}