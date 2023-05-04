/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:28:05 by jlemieux          #+#    #+#             */
/*   Updated: 2023/05/04 15:43:57 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isnum(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] <= '0' && s[i] >= '9')
			return (0);
		i++;
	}
	return (1);
}

double	atod(char *num)
{
	double	res;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	res = 0;
	if (num[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (num[i] != '\0')
	{
		res += num[i] - '0';
		if (num[i + 1] != '\0')
			res *= 10;
	}
}
