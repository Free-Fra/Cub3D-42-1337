/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlasrite <mlasrite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 14:13:56 by mlasrite          #+#    #+#             */
/*   Updated: 2020/01/19 14:00:44 by mlasrite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	manage_config(t_data *ptr)
{
	inis(ptr);
	manage_cfg(ptr);
	wall_error(ptr);
}

void	manage_cfg(t_data *ptr)
{
	int		fd;
	char	*line;

	every_lenth(ptr);
	ptr->cfg->map = (char **)malloc(sizeof(char *) * (ptr->cfg->lignes + 1));
	if ((fd = open(ptr->cfg->config, O_RDONLY)) == -1)
	{
		perror("Error\nINVALIDE FILE");
		exit(0);
	}
	while (get_next_line(fd, &line) == 1)
	{
		help_manage_cfg(ptr, line);
		if (line[0] == '1' && (line[1] == '1' || line[1] == ' '))
		{
			fill_map(ptr, line, fd);
			ptr->sec->map += 1;
			break ;
		}
		free(line);
	}
	help_manage_cfg2(ptr);
}

void	fill_map(t_data *ptr, char *line, int fd)
{
	int index;

	index = 0;
	if (line[0] == '1' && (line[1] == '1' || line[1] == ' '))
	{
		ptr->cfg->map[index++] = fill_line(line);
		free(line);
		while (get_next_line(fd, &line) == 1)
		{
			if (line[0] != '1')
			{
				perror("Error\nMAP INCORRECT : SOMETHING WRONG");
				exit(0);
			}
			ptr->cfg->map[index++] = fill_line(line);
			free(line);
		}
		free(line);
	}
	ptr->cfg->map[index] = NULL;
}

void	every_lenth(t_data *ptr)
{
	int		fd;
	char	*line;
	int		count;
	char	*str;

	count = 0;
	fd = open(ptr->cfg->config, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == '1')
		{
			str = fill_line(line);
			ptr->cfg->colones = (int)ft_strlen(str);
			free(str);
			count += 1;
		}
		free(line);
	}
	free(line);
	ptr->cfg->lignes = count;
	close(fd);
}

char	*fill_line(char *line)
{
	int		i;
	char	*str;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc(ft_strlen(line) + 1);
	while (line[i] != '\0')
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == 'S'\
		|| line[i] == 'N' || line[i] == 'E' || line[i] == 'W'\
		|| line[i] == '2')
			str[j++] = line[i];
		else if (line[i] != '1' && line[i] != '0' && line[i] != 'S'\
		&& line[i] != 'N' && line[i] != 'E' && line[i] != 'W' && line[i] != ' '\
		&& line[i] != '2')
		{
			perror("Error\nMAP INCORRECT : STRANGE LETTER");
			exit(0);
		}
		i += 1;
	}
	str[j] = '\0';
	return (str);
}
