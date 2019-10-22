/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:32:18 by merras            #+#    #+#             */
/*   Updated: 2019/10/23 00:37:06 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// DEV
# include <stdio.h>
//////

# include "../libs/centropy/includes/centropy.h"
# include "mlx.h"

# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500

# define INTER 1.1

# define MAX_ITERATIONS 30

# define R(x) (((t_render *)r)->x)

# define MAND 0
# define JULI 1
# define TREE 2

typedef struct	s_complex
{
	double		im;
	double		re;
}				t_complex;

typedef	struct	s_render
{
	int			fractal;
	void		*mlx_ptr;
	void		*win_ptr;
	double		scale;
	double		l;
	double		r;
	double		t;
	double		b;
}				t_render;

int			mandelbrot(t_complex p);
int			julia(t_complex p, t_complex c);
int			tree_index(t_complex p);

void		init_render_hooks(int f);
void		renderer(t_complex m, void *r);

t_complex	mouse_coordinate_map(int x, int y, void *r);
int			mouse_movement_hook(int x, int y, void *r);
int			mouse_roller_hook(int button, int x, int y, void *r);

t_render	*render_config(t_render *set);

#endif
