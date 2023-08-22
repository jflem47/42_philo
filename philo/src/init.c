/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:06:01 by jlemieux          #+#    #+#             */
/*   Updated: 2023/08/22 14:39:03 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_init(t_info *data)
{
	int	i;

	data->t_start = timestamp();
	i = -1;
	while (++i < data->n_philo)
	{
		data->philo[i].n = i + 1;
		data->philo[i].last_eat = 0;
		data->philo[i].fork_r = NULL;
		data->philo[i].info = data;
		data->philo[i].m_count = 0;
		pthread_mutex_init(&(data->philo[i].fork_l), NULL);
		if (i == data->n_philo - 1)
			data->philo[i].fork_r = &data->philo[0].fork_l;
		else
			data->philo[i].fork_r = &data->philo[i + 1].fork_l;
		if (pthread_create(&data->philo[i].thread, NULL, \
				&philo_life, &(data->philo[i])) != 0)
			return (-1);
	}
	i = -1;
	while (++i < data->n_philo)
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			return (-1);
	return (0);
}

int	check_num(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_value(t_info *data, char **av)
{
	if (ft_strlen(av[1]) > 11 || ft_strlen(av[2]) > 11 || \
		ft_strlen(av[3]) > 11 || ft_strlen(av[4]) > 11 || \
		ft_strlen(av[5]) > 11)
		return (1);
	data->n_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (av[5] == NULL)
		data->n_eat = INT_MAX;
	else
		data->n_eat = ft_atoi(av[5]);
	if (data->n_philo > INT_MAX)
		return (1);
	if (data->t_die > INT_MAX)
		return (1);
	if (data->t_eat > INT_MAX)
		return (1);
	if (data->t_sleep > INT_MAX)
		return (1);
	if (data->n_eat > INT_MAX)
		return (1);
	return (0);
}

int	var_init(t_info *data, char **av)
{
	if (check_num(av))
		return (printf("Invalid Arguments\n"), 1);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->m_stop, NULL);
	pthread_mutex_init(&data->m_eat, NULL);
	pthread_mutex_init(&data->dead, NULL);
	data->philo_eat = 0;
	if (ft_check_value(data, av) != 0)
		return (printf("Invalid Arguments\n"), 1);
	if (av[5] && data->n_eat == 0)
		return (1);
	data->stop = ft_calloc(sizeof(int), 1);
	data->philo = malloc(sizeof(t_philo) * data->n_philo);
	if (data->philo == NULL)
		return (2);
	return (0);
}
