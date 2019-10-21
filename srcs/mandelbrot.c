/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:31:26 by merras            #+#    #+#             */
/*   Updated: 2019/06/26 03:28:25 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    mandelbrot_renderer(t_xy xy)
{
    int x;
    int y;
    double re;
    double im;

    int conv;

    x = -1;
    while (++x < xy.width)
    {
        y = -1;
        while (++y < xy.height)
        {
            re = ((xy.r_max - xy.r_min)*x)/WIDTH  + xy.r_min;
            im  = ((xy.i_max - xy.i_min)*y)/HEIGHT + xy.i_min;
            conv = convergence(re, im);
            mlx_pixel_put(xy.gserver, xy.win, x, y, (conv ? 0x000000 : 0xffffff));
            //mlx_pixel_put(xy.gserver, xy.win, x, y, 0xffffff);
        }
    }
}

double  ft_zoom(double a, double b, double k)
{
    printf("> %f %f %f\n", a, b, k);
    printf("# %f\n", k * (b - a) + a);
    return (k * (b - a) + a);
}

void    ft_disply_zoom(double x, double y, t_xy *xy, double flag)
{
    xy->r_min = ft_zoom(x, xy->r_min, flag ? ZOOM_IN : ZOOM_OUT);
    xy->i_min = ft_zoom(y, xy->i_min, flag ? ZOOM_IN : ZOOM_OUT);
    xy->r_max = ft_zoom(x, xy->r_max, flag ? ZOOM_IN : ZOOM_OUT);
    xy->i_max = ft_zoom(y, xy->i_max, flag ? ZOOM_IN : ZOOM_OUT);
}
void    mandelbrot_render_handler(int button, int x, int y, t_xy *xy)
{

    double re = ((xy->r_max - xy->r_min)*x)/WIDTH  + xy->r_min;
    double im  = ((xy->i_max - xy->i_min)*y)/HEIGHT + xy->i_min;
    if (button == 5)
    {
        ft_disply_zoom(re, im, xy, 0);
        mandelbrot_renderer(*xy);
    }
    if (button == 4)
    {
        ft_disply_zoom(re, im, xy, 1);
        mandelbrot_renderer(*xy);
    }
}

void	mandelbrot()
{
	t_xy	xy_init;

	xy_init = init_renderer(MANDELBROT);

    mandelbrot_renderer(xy_init);
	mlx_mouse_hook(xy_init.win, rerender_handler, &xy_init);

	mlx_loop(xy_init.gserver);
}