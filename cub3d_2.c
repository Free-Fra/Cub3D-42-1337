/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlasrite <mlasrite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:47:04 by mlasrite          #+#    #+#             */
/*   Updated: 2020/01/20 14:21:11 by mlasrite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_argv(char *str)
{
	if (str[0] == '-' && str[1] == '-' && str[2] == 's' && str[3] == 'a' &&\
		str[4] == 'v' && str[5] == 'e' && ft_strlen(str) == 6)
		return (1);
	return (0);
}

int		mooving(t_data *ptr)
{
	help_mooving(ptr);
	if (ptr->key->left == 1)
	{
		ptr->angle_a -= 5;
		if (ptr->angle_a < 0)
			ptr->angle_a += 360;
		ptr->p_angle = ptr->angle_a + 30;
	}
	else if (ptr->key->right == 1)
	{
		ptr->angle_a += 5;
		ptr->p_angle = ptr->angle_a + 30;
	}
	if (ptr->angle_a > 360)
		ptr->angle_a = findmod(ptr->angle_a, 360);
	ptr->draw_x = -1;
	clear(ptr);
	draw_everything(ptr->player_x, ptr->player_y, ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
	return (0);
}

void	help_mooving(t_data *ptr)
{
	if (ptr->key->up == 1)
	{
		if (check_wall_up(ptr) == 0)
		{
			ptr->player_x += cos(degtorad(ptr->angle_a + 30)) * 10.0;
			ptr->player_y += sin(degtorad(ptr->angle_a + 30)) * 10.0 * -1;
		}
	}
	else if (ptr->key->down == 1)
	{
		if (check_wall_down(ptr) == 0)
		{
			ptr->player_x += cos(degtorad(ptr->angle_a + 30)) * 10.0 * -1;
			ptr->player_y += sin(degtorad(ptr->angle_a + 30)) * 10.0;
		}
	}
}

int		exiter(int key, void *param)
{
	t_data *ptr;

	ptr = (t_data *)param;
	key = 0;
	exit(0);
	return (0);
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	if (!n || dest == src)
		return (dest);
	while (n--)
		*str1++ = *str2++;
	return (dest);
}
