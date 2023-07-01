/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:36:48 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/01 12:57:31 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game_info	game;

	if (argc != 2)
		print_filename_error(0);
	check_file_length_extension(ft_strlen(argv[1]), argv[1]);
	init_game(&game, argv[1]);
	run_game(&game);
	return (0);
}
