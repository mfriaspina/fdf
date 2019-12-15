/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 18:34:25 by mfrias            #+#    #+#             */
/*   Updated: 2019/06/25 15:58:22 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exagerate(t_point *point)
{
	t_point *head;
	int		magnitude;

	magnitude = 4;
	head = point;
	while (point)
	{
		point->z *= magnitude;
		point = point->next;
	}
	iso(head);
}

void	move(t_point *point, char axis, int distance)
{
	if (axis == 'x')
	{
		while (point)
		{
			point->x += distance;
			point = point->next;
		}
	}
	else if (axis == 'y')
	{
		while (point)
		{
			point->y += distance;
			point = point->next;
		}
	}
}

void	zoom(t_point *point, char direction, int magnitude)
{
	if (direction == 'i')
	{
		while (point)
		{
			point->x *= magnitude;
			point->y *= magnitude;
			point->z *= magnitude;
			point = point->next;
		}
	}
	if (direction == 'o')
	{
		while (point)
		{
			point->x /= magnitude;
			point->y /= magnitude;
			point->z /= magnitude;
			point = point->next;
		}
	}
}

void	center(t_point *point)
{
	while (point->x < 200)
		move(point, 'x', 50);
	while (point->x > 1720)
		move(point, 'x', -50);
	while (point->y < 200)
		move(point, 'y', 50);
	while (point->y > 1080)
		move(point, 'y', -50);
}
