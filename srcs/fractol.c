/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:31:26 by merras            #+#    #+#             */
/*   Updated: 2019/10/23 22:55:53 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage()
{
	ft_putendl("./fractol <name>");
	ft_putendl("options:");
	ft_putendl("\t1");
	ft_putendl("\t2");
	ft_putendl("\t3");
}

void	render_fractal(char *name)
{
	if (!ft_strcmp(name, "1"))
		init_render_hooks(MAND);
	else if (!ft_strcmp(name, "2"))
		init_render_hooks(JULI);
	else if (!ft_strcmp(name, "3"))
		init_render_hooks(CUBE);
	else
		print_usage();
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		print_usage();	
		return (0);
	}
	render_fractal(argv[1]);
}
