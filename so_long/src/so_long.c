/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:36:48 by youyoon           #+#    #+#             */
/*   Updated: 2023/06/28 20:40:56 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check(void)
{
	system("leaks so_long");
}

int	main(int argc, char *argv[])
{
	t_game_info	game;

	atexit(check);
	if (argc != 2)
		print_filename_error(0);
	system("leaks so_long");
	check_file_length_extension(ft_strlen(argv[1]), argv[1]);
	system("leaks so_long");
	init_game(&game, argv[1]);
	system("leaks so_long");
	run_game(&game);
	system("leaks so_long");
	return (0);
}
