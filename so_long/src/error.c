/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:12:23 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/01 12:29:53 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_filename_error(int error_num)
{
	if (error_num == 0)
		ft_printf("Error\n./so_long [filename].ber\n");
	else if (error_num == 1)
		ft_printf("Error\nFile does not exist\n");
	else if (error_num == 2)
		ft_printf("Error\nExtension Error (.ber)\n");
	else if (error_num == 3)
		ft_printf("Error\nFilename has to be longer than 4 characters\n");
	exit(1);
}

void	print_map_error_message(int error_num, t_game_info *game)
{
	if (error_num == 0)
		ft_printf("Error\nValid object : 0, 1, P, E, C ONLY\n");
	else if (error_num == 1)
		ft_printf("Error\nIt has to be surrounded by wall\n");
	else if (error_num == 2)
		ft_printf("Error\nPlayer has to only one\n");
	else if (error_num == 3)
		ft_printf("Error\nExit has to only one\n");
	else if (error_num == 4)
		ft_printf("Erorr\nNot valid path\n");
	else if (error_num == 5)
		ft_printf("Error\nIt has to be rectangular\n");
	else if (error_num == 6)
		ft_printf("Error\nMap is empty\n");
	else if (error_num == 7)
		ft_printf("Error\nMap must contain at least 1 collectible.\n");
	else if (error_num == 8)
		ft_printf("Error\nClose error\n");
	else if (error_num == 9)
		ft_printf("Error\nMemory has not enough\n");
	free_memory(game);
	exit(1);
}
