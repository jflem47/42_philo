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
	while (s[i] != '\0')
	{
		if (s[i] <= '0' && s[i] >= '9')
			return (0);
		i++;
	}
	return (1);
}

double	ft_atod(char *num)
{
	double	res;
	int		i;

	i = 0;
	res = 0;
	while (num[i] != '\0')
	{
		res += num[i] - '0';
		if (num[i + 1] != '\0')
			res *= 10;
		i++;
	}
	return (res);
}

void	parse_args(char **av, int ac, t_env *env)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (!ft_isnum(av[i++]))
		{
			printf("philo: invalid arguments\n");
			exit(EXIT_FAILURE);
		}
	}
	env->nb_philos = ft_atod(av[1]);
	env->ttd = ft_atod(av[2]);
	env->tte = ft_atod(av[3]);
	env->tts = ft_atod(av[4]);
	if (ac == 6)
		env->times_must_eat = ft_atod(av[5]);
}
