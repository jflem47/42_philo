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

//STRUCTS
typedef struct s_env
{
	int		nb_philos;
	double	tte;
	double	ttd;
	double	tts;
	double	times_must_eat;
	t_table	**table;
}			t_env;

typedef struct s_philo
{
	int		num;
	int		eating;
	int		sleeping;
	int		fork;
}			t_philo;

typedef struct s_table
{
	t_philo	*philo;
	t_table	*next;
	t_table	*prev;
}			t_table;

//PARSING
void		parse_args(char **av, int ac, t_env *env);

//UTILS
double		ft_atod(char *num);
int			ft_isnum(char *s);

//TABLE
void		init_table(t_env *env);
t_table		*add_seat(t_table **table, t_philo *philo);
t_philo		*get_philo(t_table **table, int index);
int			table_size(t_table **table);
void		create_table(t_env *env);

//MAIN
void		philo(t_env *env);

#endif