/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:42:55 by tchampio          #+#    #+#             */
/*   Updated: 2024/12/26 15:24:13 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include <mlx.h>
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363

void	ft_move_up(t_data *data)
{
	int		oldx;
	int		oldy;
	char	oldchar;

	if (data->map->map[data->player-> y - 1][data->player->x] == '1')
		return ;
	if (data->map->map[data->player-> y - 1][data->player->x] == 'C')
		data->player->points += 1;
	if (data->map->map[data->player-> y - 1][data->player->x] == 'E')
	{
		if (data->player->points < data->map->points_to_get)
			return ;
		ft_printf("Congrats! You won with %d, you have made %d movements\n",
			data->player->points, data->player->movementcount + 1);
		ft_destroy(data);
	}
	ft_printf("Moving up\n");
	oldx = data->player->x;
	oldy = data->player->y;
	oldchar = data->map->map[oldy][oldx];
	data->player->y -= 1;
	data->map->map[data->player->y][data->player->x] = 'P';
	data->map->map[oldy][oldx] = '0';
}

void	ft_move_down(t_data *data)
{
	int	oldx;
	int	oldy;

	if (data->map->map[data->player-> y + 1][data->player->x] == '1')
		return ;
	if (data->map->map[data->player-> y + 1][data->player->x] == 'C')
		data->player->points += 1;
	if (data->map->map[data->player-> y + 1][data->player->x] == 'E')
	{
		if (data->player->points < data->map->points_to_get)
			return ;
		ft_printf("Congrats! You won with %d, you have made %d movements\n",
			data->player->points, data->player->movementcount + 1);
		ft_destroy(data);
	}
	ft_printf("Moving down\n");
	oldx = data->player->x;
	oldy = data->player->y;
	data->player->y += 1;
	data->map->map[data->player->y][data->player->x] = 'P';
	data->map->map[oldy][oldx] = '0';
}

void	ft_move_left(t_data *data)
{
	int		oldx;
	int		oldy;
	char	oldchar;

	if (data->map->map[data->player-> y][data->player->x - 1] == '1')
		return ;
	if (data->map->map[data->player-> y][data->player->x - 1] == 'C')
		data->player->points += 1;
	if (data->map->map[data->player-> y][data->player->x - 1] == 'E')
	{
		if (data->player->points < data->map->points_to_get)
			return ;
		ft_printf("Congrats! You won with %d, you have made %d movements\n",
			data->player->points, data->player->movementcount + 1);
		ft_destroy(data);
	}
	ft_printf("Moving left\n");
	oldx = data->player->x;
	oldy = data->player->y;
	oldchar = data->map->map[oldy][oldx];
	data->player->x -= 1;
	data->map->map[data->player->y][data->player->x] = 'P';
	data->map->map[oldy][oldx] = '0';
}

void	ft_move_right(t_data *data)
{
	int		oldx;
	int		oldy;
	char	oldchar;

	if (data->map->map[data->player-> y][data->player->x + 1] == '1')
		return ;
	if (data->map->map[data->player-> y][data->player->x + 1] == 'C')
		data->player->points += 1;
	if (data->map->map[data->player-> y][data->player->x + 1] == 'E')
	{
		if (data->player->points < data->map->points_to_get)
			return ;
		ft_printf("Congrats! You won with %d, you have made %d movements\n",
			data->player->points, data->player->movementcount + 1);
		ft_destroy(data);
	}
	ft_printf("Moving right\n");
	oldx = data->player->x;
	oldy = data->player->y;
	oldchar = data->map->map[oldy][oldx];
	data->player->x += 1;
	data->map->map[data->player->y][data->player->x] = 'P';
	data->map->map[oldy][oldx] = '0';
}

void	ft_move(int keycode, t_data *data)
{
	if (keycode == UP)
		ft_move_up(data);
	else if (keycode == DOWN)
		ft_move_down(data);
	else if (keycode == LEFT)
		ft_move_left(data);
	else if (keycode == RIGHT)
		ft_move_right(data);
	else
		return ;
	data->player->movementcount += 1;
	ft_printf("Player has moved" GRN " %d" RST" times\n",
		data->player->movementcount);
	ft_display_map(data);
}
