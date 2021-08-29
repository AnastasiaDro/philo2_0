/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:26:23 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/26 17:48:41 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	check_args(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Invalid arguments number!\n");
		exit(1);
	}
}
