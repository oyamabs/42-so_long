/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:57:27 by tchampio          #+#    #+#             */
/*   Updated: 2024/12/26 13:37:20 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_destroy(data);
	ft_move(keycode, data);
	return (0);
}

void	exiterror(const char *msg)
{
	ft_printf(RED "%s\n" RST, msg);
	exit(1);
}
