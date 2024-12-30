/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcreate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:10:17 by tchampio          #+#    #+#             */
/*   Updated: 2024/12/26 13:37:27 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <fcntl.h>

void	ft_init_map(t_data *data, const char *filename)
{
	ft_printf("Initializing " GRN "Map\n" RST);
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		ft_destroy(data);
	ft_bzero(data->map, sizeof(t_map));
	data->map->filename = (char *)filename;
	ft_get_width_height_check_rect(data, data->map);
	ft_readmap(data->map);
}

void	ft_get_width_height_check_rect(t_data *data, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map->filename, O_RDONLY);
	if (fd < 0)
		exiterror("Can't open file");
	line = get_next_line(fd);
	if (!line)
		exiterror("File seems empty\n");
	while (line[map->width])
		(map->width)++;
	while (line)
	{
		if (ft_strlen(line) != map->width)
		{
			free(line);
			ft_destroy(data);
		}
		(map->height)++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	ft_readmap(t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(map->filename, O_RDONLY);
	map->map = (char **)malloc(sizeof(char *) * (map->height + 1));
	map->mapflood = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->map || !map->mapflood)
		exiterror("Can't malloc");
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map->map[i] = line;
		map->mapflood[i] = ft_strdup(line);
		line = get_next_line(fd);
		i++;
	}
	map->map[i] = NULL;
	free(line);
	close(fd);
}

void	ft_free_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->height + 1)
		free(map->map[i++]);
	i = 0;
	while (i < map->height)
		free(map->mapflood[i++]);
	free(map->map);
	free(map->mapflood);
}
