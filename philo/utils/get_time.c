/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:35:38 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/19 15:35:57 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <sys/time.h>

size_t	getTime(void)
{
	size_t			milisec;
	struct timeval	t;

	gettimeofday(&t, NULL);
	milisec = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (milisec);
}
