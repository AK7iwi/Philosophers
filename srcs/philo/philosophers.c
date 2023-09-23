/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:00:08 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/23 17:27:57 by mfeldman         ###   ########.fr       */
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
		philo->id = philo->nb_philo;
		// philo->next = NULL;
		philo->nb_philo--;
		// printf("%i%s", philo->id, "\n");
	}
}

void	philosophers(t_philo *philo)
{
	set_philo(philo);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	philo;
	t_error	error;

	ft_bzero(&data, sizeof(t_data));
	ft_bzero(&philo, sizeof(t_philo));
	ft_bzero(&error, sizeof(t_error));
	data.error = &error;
	data.philo = &philo;
	parsing(argc, argv, data.error);
	philo.nb_philo = ft_atoi(argv[1]);
	printf("%i", data.philo->nb_philo);
	if (!error.error_g)
		philosophers(&philo);
	return (0);
}
