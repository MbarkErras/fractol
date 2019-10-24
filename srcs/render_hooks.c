/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:28:40 by merras            #+#    #+#             */
/*   Updated: 2019/10/24 00:01:17 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	mouse_coordinate_map(int x, int y, void *r)
{
	t_complex	m;

	m.re = (R(r) - R(l)) / WINDOW_WIDTH * x + R(l);
	m.im = (R(t) - R(b)) / WINDOW_HEIGHT * (WINDOW_HEIGHT - y) + R(b);
	return (m);
}

int			mouse_movement_hook(int x, int y, void *r)
{
	if (R(fractal) != JULI)
		return (0);
	renderer(mouse_coordinate_map(x, y, r),
	r);
	return (0);
}

int			mouse_roller_hook(int button, int x, int y, void *r)
{
	t_complex	m;

	if (button == 5 || button == 4)
	{
		m = mouse_coordinate_map(x, y, r);
		R(l) = m.re + ((R(l) - m.re) * (button == 5 ? INTER : 1 / INTER));
		R(r) = m.re + ((R(r) - m.re) * (button == 5 ? INTER : 1 / INTER));
		R(b) = m.im + ((R(b) - m.im) * (button == 5 ? INTER : 1 / INTER));
		R(t) = m.im + ((R(t) - m.im) * (button == 5 ? INTER : 1 / INTER));
		renderer(m, r);
	}
	return (0);
}

int			esc_handler(int keycode, void *r)
{
	if (keycode == 53)
	{
		mlx_destroy_window(R(mlx_ptr), R(win_ptr));
		exit(0);
	}
	return (0);
}
