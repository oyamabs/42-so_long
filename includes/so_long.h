/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 05:02:49 by tchampio          #+#    #+#             */
/*   Updated: 2024/12/26 13:46:20 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"
# define RST "\e[0m"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# include <stdbool.h>
# include <stddef.h>

typedef struct s_map
{
	size_t	height;
	size_t	width;
	int		points_to_get;
	int		spawnpoints;
	int		exits;
	int		reachable_points;
	int		reachable_exits;
	int		startx;
	int		starty;
	char	*filename;
	char	**map;
	char	**mapflood;
}	t_map;

typedef struct s_texture
{
	void	*img;
	char	*file;
	int		width;
	int		height;
}	t_texture;

typedef struct s_player
{
	int	x;
	int	y;
	int	points;
	int	movementcount;
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_map		*map;
	t_player	*player;
	t_texture	*textures[5];
}	t_data;

void	ft_get_width_height_check_rect(t_data *data, t_map *map);
int		ft_destroy(t_data *data);
void	ft_readmap(t_map *map);
void	ft_free_map(t_map *map);
bool	ft_check_map(t_data *data);
void	ft_load_textures(t_data *data);
void	ft_move(int keycode, t_data *data);
void	ft_display_map(t_data *data);
void	ft_init_map(t_data *data, const char *filename);
int		ft_key_hook(int keycode, t_data *data);
void	exiterror(const char *msg);

#endif
