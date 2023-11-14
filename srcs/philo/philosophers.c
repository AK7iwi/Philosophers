/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:00:08 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/14 20:42:51 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo*)arg;
	//moif la place du mutex
	pthread_mutex_lock(&philo[philo->id - 1].fork);
	while(!is_dead(philo) && !is_max_eat(philo))
	{
		if(philo->id % 2  == 0)
			ft_sleep(philo);
		else 
			ft_eat(philo);
		ft_print(philo);
	}
	pthread_mutex_unlock(&philo[philo->id - 1].fork);
	// ft_print(data);
	return (NULL);
}

void	philosophers(t_data *data, t_philo *philo, char **argv)
{
	init_struct_and_argv_value(data, argv);
	if(init_philo_and_mutex(data, philo) || init_thread(data, philo))
		return ;
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo *philo;
	t_error	error;

	ft_bzero(&data, sizeof(t_data));
	philo = NULL;
	ft_bzero(&error, sizeof(t_error));
	data.error = &error;
	parsing(argc, argv, data.error);
	if (!data.error->error_g)
		philosophers(&data, philo, argv);
	ft_destroy(&data,philo);
	free(philo);
	return (0);
}
