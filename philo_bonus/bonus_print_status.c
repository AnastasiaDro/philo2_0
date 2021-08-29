/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_print_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:12:25 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/26 18:12:27 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	b_print_status(t_bphilo *bphilo, char *status, t_bdata *bdata)
{
	sem_wait(bdata->print_sem);
	printf("%lu %d %s\n", getTime() - bphilo->start, bphilo->index + 1, status);
	sem_post(bdata->print_sem);
}
