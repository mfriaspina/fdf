/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:10:16 by mfrias            #+#    #+#             */
/*   Updated: 2019/06/25 19:53:06 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection(t_point *point)
{
	int previous_x;
	int previous_y;

	move(point, 'x', 400);
	while (point)
	{
		previous_x = point->x;
		previous_y = point->y;
		point->x = (previous_x - previous_y) * cos(0.46373398);
		point->y = -point->z + (previous_x + previous_y) * sin(0.46373398);
		point = point->next;
	}
}

void	iso(t_point *point)
{
	int	previous_x;
	int	previous_y;

	move(point, 'x', 400);
	while (point)
	{
		previous_x = point->x;
		previous_y = point->y;
		point->x = (previous_x - previous_y) * cos(0.523599);
		point->y = -point->z + (previous_x + previous_y) * sin(0.523599);
		point = point->next;
	}
}

void	x_rotate(t_point *point, int angle)
{
	int	previous_y;
	int	previous_z;

	while (point)
	{
		previous_y = point->y;
		previous_z = point->z;
		point->y = previous_y * cos(angle) + previous_z * sin(angle);
		point->z = -previous_y * sin(angle) + previous_z * cos(angle);
		point = point->next;
	}
}

void	y_rotate(t_point *point, int angle)
{
	int	previous_x;
	int	previous_z;

	while (point)
	{
		previous_x = point->x;
		previous_z = point->z;
		point->x = previous_x * cos(angle) + previous_z * sin(angle);
		point->z = -previous_x * sin(angle) + previous_z * cos(angle);
		point = point->next;
	}
}

void	z_rotate(t_point *point, int angle)
{
	int	previous_x;
	int	previous_y;

	while (point)
	{
		previous_x = point->x;
		previous_y = point->y;
		point->x = previous_x * cos(angle) - previous_y * sin(angle);
		point->y = previous_x * sin(angle) + previous_y * cos(angle);
		point = point->next;
	}
}
