/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:32:18 by merras            #+#    #+#             */
/*   Updated: 2019/10/22 04:10:49 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// DEV
# include <stdio.h>
//////

# include "../libs/centropy/includes/centropy.h"
# include "mlx.h"

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000

# define SCALE 1.1

# define MAX_ITERATIONS 100

# define R(x) ((t_render *)r)->x

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
	void		*mlx_ptr;
	void		*win_ptr;
	int			fractal;
	double		scale;
	double		l;
	double		r;
	double		t;
	double		b;
}				t_render;

int		mandelbrot(t_complex p);
int		julia(t_complex p, t_complex c);
int		tree_index(t_complex p);

int		renderer(int button, int x, int y, void *r);

#endif
