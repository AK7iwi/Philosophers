/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:11:22 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/14 20:41:42 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_thread(t_data *data, t_philo *philo)
{
	uint8_t	i;
	i = 0;

	data->start = get_current_time(); //test
	while(i < data->nb_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, &ft_routine, &philo[i]))
			return (1);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(philo[i].thread, NULL))
			return (1);
		i++;
	}
	return(0);
}

int	init_philo_and_mutex(t_data *data, t_philo *philo)
{
	uint8_t	i;
	i = 0;
	philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!philo)
		return (1);
	while (i < data->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].last_meal = 0;
		philo[i].nb_meal = 0;
		philo[i].ptr = data;
		if(pthread_mutex_init(&philo[i].fork, NULL))
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