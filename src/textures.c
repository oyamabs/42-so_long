/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:39:01 by tchampio          #+#    #+#             */
/*   Updated: 2024/12/26 13:26:22 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "mlx.h"
#define WALL_TEXTURE	"res/wall.xpm"
#define FLOOR_TEXTURE	"res/floor.xpm"
#define COIN_TEXTURE	"res/coin.xpm"
#define PLAYER_TEXTURE	"res/player.xpm"
#define EXIT_TEXTURE	"res/exit.xpm"

t_texture	*ft_load_texture(t_data *data, char *texturefile)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	if (!texture)
	{
		ft_printf(RED "Can't malloc() for texture\n" RST);
		ft_destroy(data);
	}
	texture->img = mlx_xpm_file_to_image(data->mlx, texturefile,
			&texture->width, &texture->height);
	if (!texture->img)
	{
		ft_printf(RED "Can't initialize texture\n" RST);
		ft_destroy(data);
	}
	return (texture);
}

void	ft_load_textures(t_data *data)
{
	ft_printf("Initializing " GRN "Textures\n" RST);
	data->textures[0] = ft_load_texture(data, WALL_TEXTURE);
	data->textures[1] = ft_load_texture(data, FLOOR_TEXTURE);
	data->textures[2] = ft_load_texture(data, COIN_TEXTURE);
	data->textures[3] = ft_load_texture(data, PLAYER_TEXTURE);
	data->textures[4] = ft_load_texture(data, EXIT_TEXTURE);
}
