/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:41:24 by abrochie          #+#    #+#             */
/*   Updated: 2023/08/03 16:07:09 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	print(t_philo *philo, char *str)
{
	long int	time;

	pthread_mutex_lock(&(philo->info->print));
	time = timestamp() - philo->info->t_start;
	if (!philo->info->stop && time >= 0 && time <= INT_MAX && !is_dead(philo,
			0))
		printf("%lld %d %s", timestamp() - philo->info->t_start, philo->n, str);
	pthread_mutex_unlock(&(philo->info->print));
}
