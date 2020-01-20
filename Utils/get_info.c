/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlasrite <mlasrite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 22:27:21 by mlasrite          #+#    #+#             */
/*   Updated: 2020/01/18 16:11:14 by mlasrite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_info(t_data *ptr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	get_info_sprite(ptr);
	while (ptr->cfg->map[i] != NULL)
	{
		j = 0;
		while (ptr->cfg->map[i][j] != '\0')
		{
			if (ptr->cfg->map[i][j] == 'N')
			{
				ptr->player_x = (j + 0.5) * 64;
				ptr->player_y = (i + 0.5) * 64;
				ptr->angle_a = 60;
			}
			get_info_2(i, j, ptr);
			j += 1;
		}
		i += 1;
	}
}

void	get_info_2(int i, int j, t_data *ptr)
{
	if (ptr->cfg->map[i][j] == 'S')
	{
		ptr->player_x = (j + 0.5) * 64;
		ptr->player_y = (i + 0.5) * 64;
		ptr->angle_a = 240;
	}
	else if (ptr->cfg->map[i][j] == 'E')
	{
		ptr->player_x = (j + 0.5) * 64;
		ptr->player_y = (i + 0.5) * 64;
		ptr->angle_a = -30;
	}
	else if (ptr->cfg->map[i][j] == 'W')
	{
		ptr->player_x = (j + 0.5) * 64;
		ptr->player_y = (i + 0.5) * 64;
		ptr->angle_a = 150;
	}
}

int		check_wall_up(t_data *ptr)
{
	int		a;
	int		b;
	float	x;
	float	y;

	x = cos(degtorad(ptr->angle_a + 30)) * 60 + ptr->player_x;
	y = sin(degtorad(ptr->angle_a + 30)) * 60 * -1 + ptr->player_y;
	a = x / ptr->tile_size;
	b = y / ptr->tile_size;
	if (ptr->cfg->map[b][a] == '1' || ptr->cfg->map[b][a] == '2')
		return (1);
	return (0);
}

int		check_wall_down(t_data *ptr)
{
	int		a;
	int		b;
	float	x;
	float	y;

	x = cos(degtorad(ptr->angle_a + 30)) * 60 * -1 + ptr->player_x;
	y = sin(degtorad(ptr->angle_a + 30)) * 60 + ptr->player_y;
	a = x / ptr->tile_size;
	b = y / ptr->tile_size;
	if (ptr->cfg->map[b][a] == '1' || ptr->cfg->map[b][a] == '2')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int res;
	int	i;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i += 1;
	}
	return (res);
}
