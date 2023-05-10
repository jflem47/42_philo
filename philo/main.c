/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:08:36 by jlemieux          #+#    #+#             */
/*   Updated: 2023/05/10 14:28:10 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_env	env;

	if (ac < 5)
		return (printf("philo: not enough arguments.\n"), EXIT_FAILURE);
	parse_args(av, ac, &env);
	return (EXIT_SUCCESS);
}
