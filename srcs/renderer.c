/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 08:26:38 by merras            #+#    #+#             */
/*   Updated: 2019/10/22 04:10:14 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		fractal_dispatcher(int f, t_complex p, t_complex c)
{
	if (f == MAND)
		return (mandelbrot(p));
	if (f == JULI)
		return (julia(p, c));
	if (f == TREE)
		return (tree_index(p));
	return (420);
}

int		renderer(int button, int x, int y, void *r)
{
	int		i;
	int		j;
	
	double	zoom_shift_x = (R(r) - R(l)) / WINDOW_WIDTH * x + R(l);
	double	zoom_shift_y = (R(t) - R(b)) / WINDOW_HEIGHT * (WINDOW_HEIGHT - y) + R(b);
	if (button == 5 || button == 4)
	{
		R(l) *= (button == 5 ? SCALE : 1 / SCALE);
		R(r) *= (button == 5 ? SCALE : 1 / SCALE);
		R(t) *= (button == 5 ? SCALE : 1 / SCALE);
		R(b) *= (button == 5 ? SCALE : 1 / SCALE);
		R(l) += zoom_shift_x * 0.2;
    	R(r) += zoom_shift_x * 0.2;
    	R(t) += zoom_shift_y * 0.2;
	  	R(b) += zoom_shift_y * 0.2;
	}
	i = 0;
	printf("*** %f %f\n", zoom_shift_x, zoom_shift_y);
	printf("%f %f %f %f\n", R(l), R(r), R(t), R(b));
	while (i < WINDOW_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGHT)
		{
			//printf("[%f %f]\n", (R(r) - R(l)) / WINDOW_WIDTH * i + R(l), (R(t) - R(b)) / WINDOW_HEIGHT * j + R(b));
			if (fractal_dispatcher(R(fractal),
				(t_complex){(R(r) - R(l)) / WINDOW_WIDTH * i + R(l),
				(R(t) - R(b)) / WINDOW_HEIGHT * (WINDOW_HEIGHT - j) + R(b)},
				(t_complex){(R(r) - R(l)) / WINDOW_WIDTH * x + R(l),
				(R(t) - R(b)) / WINDOW_HEIGHT * (WINDOW_HEIGHT - y) + R(b)}))
				mlx_pixel_put(R(mlx_ptr), R(win_ptr), (int)i, (int)j, 0);
			else
				mlx_pixel_put(R(mlx_ptr), R(win_ptr), (int)i, (int)j, 0xFFFFFF);
			j++;
		}
		i++;
	}
	return (0);
}

void	render_wrapper(int f)
{
	t_render	r;

	r.fractal = f;
	r.scale = 1;
	r.l = -2;
	r.r = 2;
	r.b = -2;
	r.t = 2;
	r.mlx_ptr = mlx_init();
	r.win_ptr = mlx_new_window(r.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
				"fractol");
	renderer(0, 0, 0, &r);
	mlx_mouse_hook(r.win_ptr, renderer, &r);
	mlx_loop(r.mlx_ptr);
}















