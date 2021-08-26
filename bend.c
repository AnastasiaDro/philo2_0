/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bend.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:20:53 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/26 18:21:09 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	bend(t_bdata *bdata)
{
	free(bdata->pids);
	sem_unlink(SEMAPHORE);
	sem_unlink(PRINT);
	return (0);
}
