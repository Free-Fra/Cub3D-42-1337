/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlasrite <mlasrite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:54:15 by mlasrite          #+#    #+#             */
/*   Updated: 2020/01/20 00:06:30 by mlasrite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		clear(t_data *ptr)
{
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_ptr);
	mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
	ptr->img_ptr = mlx_new_image(ptr->mlx_ptr,\
	ptr->cfg->reso_x, ptr->cfg->reso_y);
}

void		initialize(t_data *ptr)
{
	get_info(ptr);
	ptr->draw_x = -1;
	ptr->tile_size = 64;
	ptr->p_angle = ptr->angle_a + 30;
	ptr->color = 0xFFFFFF;
	ptr->correct_distance = 0;
	ptr->key->up = 0;
	ptr->key->down = 0;
	ptr->key->right = 0;
	ptr->key->left = 0;
	ptr->error = 0;
}

static char	*ft_strdup(const char *s1)
{
	char	*s;
	int		len;
	int		i;

	len = 0;
	while (s1[len])
		len++;
	len++;
	s = malloc(len * sizeof(char) + 1);
	if (s == 0)
		return (0);
	i = -1;
	while (s1[++i])
		s[i] = s1[i];
	s[i] = '\0';
	return (s);
}

static	int	readbytes(int fd, char **stock)
{
	char		*buff;
	int			bytes;
	char		*tmp;

	if (!(buff = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	bytes = read(fd, buff, BUFFER_SIZE);
	if (bytes > 0)
	{
		buff[bytes] = '\0';
		tmp = ft_strjoin(*stock, buff);
		if (!tmp)
			return (-1);
		free(*stock);
		*stock = tmp;
	}
	free(buff);
	return (bytes);
}

int			get_next_line(int fd, char **line)
{
	static char	*stock;
	char		*index;
	int			bytes;

	if ((!stock && ((stock = ft_calloc(1, 1))) == NULL) || fd < 0 || !line)
		return (-1);
	while ((index = ft_strchr(stock, '\n')) == NULL)
	{
		bytes = readbytes(fd, &stock);
		if (bytes == 0)
		{
			*line = ft_strdup(stock);
			free(stock);
			stock = NULL;
			return (0);
		}
		else if (bytes < 0)
			return (-1);
		index = ft_strchr(stock, '\n');
	}
	*line = ft_substr(stock, 0, index - stock);
	index = ft_strdup(index + 1);
	free(stock);
	stock = index;
	return (1);
}
