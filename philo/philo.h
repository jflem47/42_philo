/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:12:32 by jlemieux          #+#    #+#             */
/*   Updated: 2023/05/04 15:29:10 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_env
{
	int		nb_philos;
	double	tte;
	double	ttd;
	double	tts;
	double	times_must_eat;
}			t_env;

//PARSING
void		parse_args(char **av, t_env *env);

//UTILS
double		ft_atod(char *num);

#endif