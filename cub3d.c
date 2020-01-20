/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlasrite <mlasrite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 21:18:17 by mlasrite          #+#    #+#             */
/*   Updated: 2020/01/20 14:16:52 by mlasrite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		keys_release(int key, void *param)
{
	t_data *ptr;

	ptr = (t_data *)param;
	if (key == 126)
		ptr->key->up = -1;
	else if (key == 125)
		ptr->key->down = -1;
	else if (key == 124)
		ptr->key->left = -1;
	else if (key == 123)
		ptr->key->right = -1;
	return (0);
}

int		keys_press(int key, void *param)
{
	t_data *ptr;

	ptr = (t_data *)param;
	if (key == 126)
		ptr->key->up = 1;
	else if (key == 125)
		ptr->key->down = 1;
	else if (key == 124)
		ptr->key->left = 1;
	else if (key == 123)
		ptr->key->right = 1;
	else if (key == 53)
		exit(0);
	ptr->draw_x = 0;
	return (0);
}

void	help_main(t_data *ptr, char *argv)
{
	ptr = malloc(sizeof(t_data));
	ptr->txt = malloc(sizeof(t_img));
	ptr->cfg = malloc(sizeof(t_cfg));
	ptr->obj = malloc(sizeof(t_sp));
	ptr->key = malloc(sizeof(t_key));
	ptr->sec = malloc(sizeof(t_check));
	ptr->bmp = malloc(sizeof(t_bmp));
	ptr->mlx_ptr = mlx_init();
	ptr->cfg->config = argv;
	manage_config(ptr);
	ptr->list = malloc(sizeof(t_spr) * count_objets(ptr));
	initialize(ptr);
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, ptr->cfg->reso_x,\
	ptr->cfg->reso_y, "cub3D");
	ptr->img_ptr = mlx_new_image(ptr->mlx_ptr, ptr->cfg->reso_x,\
	ptr->cfg->reso_y);
	mlx_hook(ptr->win_ptr, 2, 0, keys_press, ptr);
	mlx_hook(ptr->win_ptr, 3, 0, keys_release, ptr);
	mlx_hook(ptr->win_ptr, 17, 0, exiter, ptr);
	mlx_loop_hook(ptr->mlx_ptr, mooving, ptr);
	mlx_loop(ptr->mlx_ptr);
}

void	help_main_2(t_data *ptr, char *argv)
{
	ptr = malloc(sizeof(t_data));
	ptr->txt = malloc(sizeof(t_img));
	ptr->cfg = malloc(sizeof(t_cfg));
	ptr->obj = malloc(sizeof(t_sp));
	ptr->key = malloc(sizeof(t_key));
	ptr->sec = malloc(sizeof(t_check));
	ptr->bmp = malloc(sizeof(t_bmp));
	ptr->mlx_ptr = mlx_init();
	ptr->cfg->config = argv;
	manage_config(ptr);
	ptr->list = malloc(sizeof(t_spr) * count_objets(ptr));
	initialize(ptr);
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, ptr->cfg->reso_x,\
	ptr->cfg->reso_y, "cub3D");
	ptr->img_ptr = mlx_new_image(ptr->mlx_ptr, ptr->cfg->reso_x,\
	ptr->cfg->reso_y);
	draw_everything(ptr->player_x, ptr->player_y, ptr);
	ft_bitmap(ptr);
}

int		main(int argc, char **argv)
{
	t_data	*ptr;

	ptr = NULL;
	if (argc == 2)
		help_main(ptr, argv[1]);
	else if (argc == 3 && check_argv(argv[2]))
		help_main_2(ptr, argv[1]);
	else
	{
		perror("Error\n");
		exit(0);
	}
}
