/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:09:45 by tchampio          #+#    #+#             */
/*   Updated: 2024/12/26 12:56:04 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <mlx.h>

void	ft_display_texture(t_data *data, int i, int j, int texture)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->textures[texture]->img, j * 32, i * 32);
}

void	ft_display_map(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width - 1)
		{
			if (data->map->map[i][j] == '1')
				ft_display_texture(data, i, j, 0);
			else if (data->map->map[i][j] == 'P')
				ft_display_texture(data, i, j, 3);
			else if (data->map->map[i][j] == 'C')
				ft_display_texture(data, i, j, 2);
			else if (data->map->map[i][j] == 'E')
				ft_display_texture(data, i, j, 4);
			else
				mlx_put_image_to_window(data->mlx, data->win,
					data->textures[1]->img, j * 32, i * 32);
			j++;
		}
		i++;
	}
}
