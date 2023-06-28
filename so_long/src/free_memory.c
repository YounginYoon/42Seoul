/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:14:01 by youyoon           #+#    #+#             */
/*   Updated: 2023/06/28 21:16:14 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*free_memory(t_game_info *game)
{
	int	i;

	i = 0;
	free(game->map.buf);
	while (i < game->map.height)
	{
		free(game->map.map_table[i]);
		free(game->map.visited[i]);
		i++;
	}
	free(game->map.map_table);
	free(game->map.visited);
	return (0);
}
