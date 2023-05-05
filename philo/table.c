#include "philo.h"

void	init_table(t_env *env)
{
	t_philo	*philo;

	env->table = (t_table **)malloc(sizeof(t_table **));
	philo = (t_philo *)malloc(sizeof(t_philo *));
	philo->eating = 0;
	philo->fork = 0;
	philo->sleeping = 0;
}

t_table	*add_seat(t_table **table, t_philo *philo)
{
	t_table	*current;
	t_philo	*philo;

	current = *table;
	if (!current)
	{
		philo = (t_philo *)malloc(sizeof(t_philo *));
		current = (t_table *)malloc(sizeof(t_table *));
		philo->eating = 0;
		philo->fork = 0;
		philo->sleeping = 0;
		current->philo = philo;
		current->next = NULL;
		current->prev = NULL;
	}
	else
	{
		while (current)
		{
		}
	}
}
