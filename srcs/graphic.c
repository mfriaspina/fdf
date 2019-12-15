/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:00:27 by mfrias            #+#    #+#             */
/*   Updated: 2019/06/27 18:58:54 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_fdf *fdf, t_point a, t_point b)
{
	int	i;
	int color;

	if (!a.z && !b.z)
		color = 0x00FF00;
	else if (a.z < 0 && b.z < 0)
		color = 0x0000FF;
	else if (a.z < 0 || b.z < 0)
		color = 0xDFF442;
	else if (a.z != b.z)
		color = 0x593D00;
	else
		color = 0xFFFFFF;
	i = (a.x * fdf->bpp / 8) + (a.y * fdf->size);
	if (!fdf->addr || a.x >= 1720 || a.x < 0 || a.y > 1080 || a.y < 0)
		return ;
	fdf->addr[i] = color;
	fdf->addr[++i] = color >> 8;
	fdf->addr[++i] = color >> 16;
	fdf->addr[++i] = 0;
}

void	line_img(t_fdf *fdf, t_point a, t_point b)
{
	t_point	delta;
	t_point	sign;
	int		error;
	int		delta_error;

	delta.x = abs(a.x - b.x);
	delta.y = abs(a.y - b.y);
	sign.x = b.x < a.x ? 1 : -1;
	sign.y = b.y < a.y ? 1 : -1;
	delta_error = delta.x - delta.y;
	while (b.x != a.x || b.y != a.y)
	{
		pixel_put(fdf, b, a);
		if ((error = delta_error * 2) > -delta.y)
		{
			delta_error -= delta.y;
			b.x += sign.x;
		}
		if (error < delta.x)
		{
			delta_error += delta.x;
			b.y += sign.y;
		}
	}
}

void	print(t_fdf *fdf, t_point *list)
{
	menu(fdf);
	ft_bzero(fdf->addr, 1720 * 1080 * (fdf->bpp / 8));
	while (list->next)
	{
		if (list->nexty)
			line_img(fdf, *list, *(*list).nexty);
		if (!list->end)
			line_img(fdf, *list, *(*list).next);
		list = list->next;
	}
}

void	menu(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 0, 0, 0xFFFFFF, "Controls:");
	mlx_string_put(fdf->mlx, fdf->win, 0, 25, 0xFFFFFF, "Enter: Top-Down");
	mlx_string_put(fdf->mlx, fdf->win, 0, 50, 0xFFFFFF, "I: 2:1 Isometric");
	mlx_string_put(fdf->mlx, fdf->win, 0, 75, 0xFFFFFF, "O: Original");
	mlx_string_put(fdf->mlx, fdf->win, 0, 100, 0xFFFFFF, "P: True Isometric");
	mlx_string_put(fdf->mlx, fdf->win, 0, 125, 0xFFFFFF, "NUMPAD: Rotate");
	mlx_string_put(fdf->mlx, fdf->win, 0, 150, 0xFFFFFF, "Arrow: Move");
	mlx_string_put(fdf->mlx, fdf->win, 0, 175, 0xFFFFFF, "+: Zoom in");
	mlx_string_put(fdf->mlx, fdf->win, 0, 200, 0xFFFFFF, "-: Zoom out");
	mlx_string_put(fdf->mlx, fdf->win, 0, 225, 0xFFFFFF, "NUMPAD 5: Center");
	mlx_string_put(fdf->mlx, fdf->win, 0, 250, 0xFFFFFF, "E: Exagerate");
}

void	reset(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	freepoint(fdf->point);
	readfile(fdf);
}
