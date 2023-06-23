/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:08:07 by youyoon           #+#    #+#             */
/*   Updated: 2023/06/23 21:14:57 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "get_next_line.h"

typedef struct s_data
{
	int		fd;
	int		height;
	int		width;
	int		player_cnt;
	int		wall_cnt;
	int		exit_cnt;
	int		r;
	int		c;
	int		cnt;
	int		collectable_cnt;

	char	**map;
	void	*floor;
	void	*wall;
	void	*collectable;
	void	*mlxp;
	void	*winp;
}	t_data;

int	read_map(t_data *game, char **argv);
#endif
