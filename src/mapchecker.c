/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:58:44 by tchampio          #+#    #+#             */
/*   Updated: 2024/12/26 12:51:12 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"

bool	ft_wall_check(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 2] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < map->width - 2)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	ft_check_characters(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (!ft_strchr("10CPEG\n", map->map[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	ft_check_bare_minimum(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
			{
				(map->spawnpoints)++;
				map->starty = i;
				map->startx = j;
			}
			if (map->map[i][j] == 'C')
				(map->points_to_get)++;
			if (map->map[i][j] == 'E')
				(map->exits)++;
			j++;
		}
		i++;
	}
}

void	ft_flood_fill(t_map *map, int x, int y)
{
	if (map->mapflood[y][x] == '1')
		return ;
	if (map->mapflood[y][x] == 'C')
		map->reachable_points++;
	if (map->mapflood[y][x] == 'E')
	{
		map->reachable_exits++;
		return ;
	}
	map->mapflood[y][x] = '1';
	ft_flood_fill(map, x + 1, y);
	ft_flood_fill(map, x, y + 1);
	ft_flood_fill(map, x - 1, y);
	ft_flood_fill(map, x, y - 1);
}

bool	ft_check_map(t_data *data)
{
	ft_printf("Checking walls\n");
	if (!ft_wall_check(data->map))
		return (false);
	ft_printf("Checking if there are forbidden characters\n");
	if (!ft_check_characters(data->map))
		return (false);
	ft_printf("Checking there is the bare minimum\n");
	ft_check_bare_minimum(data->map);
	if ((data->map->spawnpoints > 1 || data->map->spawnpoints == 0)
		|| (data->map->exits > 1 || data->map->exits == 0)
		|| data->map->points_to_get < 1)
		return (false);
	ft_printf("Checking if map is possible\n");
	ft_flood_fill(data->map, data->map->startx, data->map->starty);
	if (data->map->reachable_exits < 1
		|| data->map->reachable_points < data->map->points_to_get)
		return (false);
	return (true);
}
