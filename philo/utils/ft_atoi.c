/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:52:07 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/19 15:36:48 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoi(char *str)
{
	int		i;
	int		coef;
	long	result;

	i = 0;
	coef = 1;
	result = 0;
	while ((str[i] != '\0' && (str[i] >= '\t' \
			&& str[i] <= '\r')) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		return (-1);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += (str[i] - '0') * coef;
		if (coef > 0 && result < 0)
			return (-1);
		if (coef < 0 && result > 0)
			return (0);
		i++;
	}
	return (result);
}
