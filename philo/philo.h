/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:12:32 by jlemieux          #+#    #+#             */
/*   Updated: 2023/05/10 14:51:52 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

# define USED 1
# define FREE 0

# define TRUE 1
# define FALSE 0

//STRUCTS
typedef struct philo
{
	int		thinking;
	int		eating;
	int		sleeping;
	int		dead;
}			t_philo;
typedef struct s_env
{
	int		nb_philos;
	double	tte;
	double	ttd;
	double	tts;
	double	times_must_eat;
	int		*forks;
	t_philo	**philos;
}			t_env;

//PARSING
void		parse_args(char **av, int ac, t_env *env);

//UTILS
double		ft_atod(char *num);
int			ft_isnum(char *s);

//MAIN
void		philo(t_env *env);

//THREADS
void		eat(t_env *env);
void		think(t_env *env);
void		sleep(t_env *env);

#endif