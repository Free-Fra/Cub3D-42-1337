/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlasrite <mlasrite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:05:01 by mlasrite          #+#    #+#             */
/*   Updated: 2020/01/19 13:53:41 by mlasrite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	freeyi(char **d)
{
	int i;

	i = 0;
	while (d[i] != NULL)
		free(d[i++]);
	free(d);
}

void	wall_error(t_data *ptr)
{
	int i;

	i = 0;
	while (i++ < ptr->cfg->lignes)
	{
		if (i + 1 < ptr->cfg->lignes)
		{
			if (ft_strlen(ptr->cfg->map[i]) !=\
			ft_strlen(ptr->cfg->map[i + 1]))
			{
				perror("Error\nMAP INCORRECT : NOT THE SAME LENTH");
				exit(0);
			}
		}
	}
	i = -1;
	while (ptr->cfg->map[0][++i] != '\0')
	{
		if (ptr->cfg->map[0][i] != '1')
		{
			perror("Error\nMAP INCORRECT : FIX YOUR UP WALL");
			exit(0);
		}
	}
	help_wall_error(ptr);
}

void	help_wall_error(t_data *ptr)
{
	int i;

	i = 0;
	while (ptr->cfg->map[ptr->cfg->lignes - 1][i] != '\0')
	{
		if (ptr->cfg->map[ptr->cfg->lignes - 1][i] != '1')
		{
			perror("Error\nMAP INCORRECT : FIX YOUR DOWN WALL");
			exit(0);
		}
		i += 1;
	}
	wall_error2(ptr);
}

void	wall_error2(t_data *ptr)
{
	int i;

	i = 0;
	while (ptr->cfg->map[i] != NULL)
	{
		if (ptr->cfg->map[i][0] != '1')
		{
			perror("Error\nMAP INCORRECT : FIX YOUR LEFT WALL");
			exit(0);
		}
		i += 1;
	}
	i = 0;
	while (ptr->cfg->map[i] != NULL)
	{
		if (ptr->cfg->map[i][ptr->cfg->colones - 1] != '1')
		{
			perror("Error\nMAP INCORRECT : FIX YOUR RIGHT WALL");
			exit(0);
		}
		i += 1;
	}
	help_error2(ptr);
}

void	help_error2(t_data *ptr)
{
	int count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	j = 0;
	while (ptr->cfg->map[i] != NULL)
	{
		j = 0;
		while (ptr->cfg->map[i][j] != '\0')
		{
			if (ptr->cfg->map[i][j] == 'S' || ptr->cfg->map[i][j] == 'E' ||\
			ptr->cfg->map[i][j] == 'N' || ptr->cfg->map[i][j] == 'W')
				count += 1;
			if (count >= 2)
			{
				perror("Error\nMAP INCORRECT : TOO MANY PLAYERS");
				exit(0);
			}
			j += 1;
		}
		i += 1;
	}
	help_help_error2(count);
}
