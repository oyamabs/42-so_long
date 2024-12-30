/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 04:48:01 by tchampio          #+#    #+#             */
/*   Updated: 2024/12/26 15:04:26 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/so_long.h"
#include <mlx.h>
#include <stdlib.h>

void	ft_free_images(t_data *data)
{
	int	i;

	if (data->textures[0])
	{
		i = 0;
		while (i < 5)
		{
			ft_printf("Freeing texture[%d]\n", i);
			mlx_destroy_image(data->mlx, data->textures[i]->img);
			free(data->textures[i]);
			i++;
		}
	}
}

int	ft_destroy(t_data *data)
{
	ft_printf("Freeing win\n");
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	ft_printf("Freeing img\n");
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	ft_printf("Freeing MLX\n");
	ft_free_images(data);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->map->map)
		ft_free_map(data->map);
	if (data->map)
		free(data->map);
	if (data->player)
		free(data->player);
	if (data->mlx)
		free(data->mlx);
	free(data);
	exit(0);
	return (0);
}

void	ft_create_player(t_data *data)
{
	t_player	*player;

	ft_printf("Initializing " GRN "Player\n" RST);
	player = malloc(sizeof(*player));
	if (!player)
		ft_destroy(data);
	ft_bzero(player, sizeof(*player));
	player->x = data->map->startx;
	player->y = data->map->starty;
	data->player = player;
}

void	ft_init_data(t_data *data, const char *filename)
{
	ft_init_map(data, filename);
	if (!ft_check_map(data))
	{
		ft_printf(RED "Malformed map. Either border aren't walls or you have"
			" unexpected characters in your map. Dumbass!\n" RST);
		ft_destroy(data);
	}
	ft_printf("Initializing " GRN "MLX\n" RST);
	data->mlx = mlx_init();
	ft_printf("Initializing " GRN "Window\n" RST);
	data->win = mlx_new_window(data->mlx, data->map->width * 32 - 32,
			data->map->height * 32, "so_long");
	ft_printf("Initializing " GRN "Image\n" RST);
	data->img = mlx_new_image(data->mlx, data->map->width * 32 - 32,
			data->map->height * 32);
	ft_load_textures(data);
	ft_create_player(data);
	ft_printf("Initializing " GRN "Hooks\n" RST);
	mlx_hook(data->win, 17, 0L, ft_destroy, data);
	mlx_key_hook(data->win, ft_key_hook, data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (ft_printf(RED "Error. Usage ./so_long <map_file>\n" RST), 1);
	data = malloc(sizeof(*data));
	if (!data)
		return (ft_printf(RED "Error during malloc. Exiting.\n" RST), 1);
	ft_bzero(data, sizeof(*data));
	ft_printf("Initializing data...\n");
	ft_init_data(data, argv[1]);
	ft_display_map(data);
	ft_printf("Player ptr: %p\n", data->player);
	mlx_loop(data->mlx);
}
