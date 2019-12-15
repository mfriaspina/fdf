/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:57:11 by mfrias            #+#    #+#             */
/*   Updated: 2019/06/27 18:47:40 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	freepoint(t_point *head)
{
	t_point *next;

	while (head)
	{
		next = head->next;
		ft_memdel((void **)&head);
		head = next;
	}
}

void	freefdf(t_fdf *fdf)
{
	if (fdf->win != NULL)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->img != NULL)
		mlx_destroy_image(fdf->mlx, fdf->img);
	if (fdf->point != NULL)
		freepoint(fdf->point);
	ft_memdel((void **)&fdf);
	exit(0);
}
