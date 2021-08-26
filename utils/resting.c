/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:23:04 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/26 18:23:44 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	resting(unsigned int time)
{
	unsigned long	start;

	start = getTime();
	while (getTime() - start < (unsigned long)time)
		usleep(100);
}
