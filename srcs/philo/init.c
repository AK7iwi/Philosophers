/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:11:22 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/08 23:49:38 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_thread(t_data *data)
{
	uint8_t	i;
	i = 0;

	while(i < data->nb_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL, &ft_test, data) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL))
			return (1);
		i++;
	}
	ft_putnbr_fd(data->test, 1);
	return(0);
}

int	init_philo(t_data *data)
{
	uint8_t	i;
	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philo)
		return (1);
	while (i < data->nb_philo)
	{
		data->philo[i].id = i + 1;
		i++;
	}
	return (0);
}

int	init_mutex(t_data *data)
{
	uint8_t	i;

	i = 0;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->fork)
		return (1);
	while(i < data->nb_philo)
	{
		if(pthread_mutex_init(&data->fork[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

void	init_struct_and_argv_value(t_data *data, char **argv)
{
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if(argv[5])
		data->max_eat= ft_atoi(argv[5]);
}