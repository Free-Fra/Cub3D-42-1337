/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlasrite <mlasrite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 23:11:19 by mlasrite          #+#    #+#             */
/*   Updated: 2020/01/19 13:36:01 by mlasrite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_info_sprite(t_data *ptr)
{
	int i;
	int j;
	int index;
	int count;

	i = 0;
	j = 0;
	index = 0;
	count = count_objets(ptr);
	while (ptr->cfg->map[i] != NULL)
	{
		j = 0;
		while (ptr->cfg->map[i][j] != '\0')
		{
			if (ptr->cfg->map[i][j] == '2')
			{
				ptr->list[index].s_x = (j + 0.5) * 64;
				ptr->list[index].s_y = (i + 0.5) * 64;
				index += 1;
			}
			j += 1;
		}
		i += 1;
	}
}

int		count_objets(t_data *ptr)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (ptr->cfg->map[i] != NULL)
	{
		j = 0;
		while (ptr->cfg->map[i][j] != '\0')
		{
			if (ptr->cfg->map[i][j] == '2')
				count += 1;
			j += 1;
		}
		i += 1;
	}
	return (count);
}
