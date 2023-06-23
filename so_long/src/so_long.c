/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:36:48 by youyoon           #+#    #+#             */
/*   Updated: 2023/06/23 21:20:46 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;

	tmp = b;
	while (len--)
	{
		*tmp++ = (unsigned char)c;
	}
	return (b);
}

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_data));
	read_map(&game, argv);
	error_check(&game);
	game.mlxp = mlx_init();
	game.winp = mlx_new_window(game.mlxp, (game.width * 40), (game.height * 40), "so_long");
	
}
