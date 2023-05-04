/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:08:36 by jlemieux          #+#    #+#             */
/*   Updated: 2023/05/04 15:16:09 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	if (ac < 5)
		return (printf("philo: not enough arguments.\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
