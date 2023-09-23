/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:00:08 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/23 14:19:24 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	thread_creation()
// {
	
// }

void	set_philo(t_philo *philo)
{
	while (philo->nb_philo > 0)
	{
		philo->rank = philo->nb_philo;
		// philo->next = NULL;
		philo->nb_philo--;
		printf("%i%s", philo->rank, "\n");
	}
}

void	philosophers(t_philo *philo)
{
	set_philo(philo);
}

int	main(int argc, char **argv)
{
	t_philo	philo;
	t_error	error;

	ft_bzero(&philo, sizeof(t_philo));
	ft_bzero(&error, sizeof(t_error));
	philo.error = &error;
	parsing(argc, argv, philo.error);
	philo.nb_philo = ft_atoi(argv[1]);
	if (!error.error_g)
		philosophers(&philo);
	return (0);
}
