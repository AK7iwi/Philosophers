/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:11:22 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/23 11:48:21 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	init_thread(t_data *data, t_philo *philo)
{
	uint8_t	i;
	i = 0;

	data->start = get_current_time();
	while(i < data->nb_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, &ft_routine, &philo[i]))
			return (1);
		i++;
	}
	usleep(50);
	ft_die_or_stop(data, philo);
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(philo[i].thread, NULL))
			return (1);
		i++;
	}
	return(0);
}

bool	init_philo(t_data *data, t_philo **philo)
{
	uint8_t	i;
	
	*philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!(*philo))
		return (1);
	i = 0;
	while (i < data->nb_philo)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].last_meal = 0;
		(*philo)[i].nb_meal = 0;
		(*philo)[i].ptr_data = data;	
		i++;
	}
	return (0);
}

bool	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if(!(data->fork))
		return (1);
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->fork[i], NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->m_print, NULL))
		return (1);
	if (pthread_mutex_init(&data->m_max_eat, NULL))
		return (1);
	if (pthread_mutex_init(&data->m_last_meal, NULL))
		return (1);
	if (pthread_mutex_init(&data->m_die, NULL))
		return (1);
	return (0);
}

void	init_struct(t_data *data, char **argv)
{
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if(argv[5])
		data->max_eat= ft_atoi(argv[5]);
	else
		data->max_eat = -1;
	// if (data->nb_philo % 2 && (data->time_to_eat > data->time_to_sleep))
	// 	data->time_to_think = data->time_to_eat - data->time_to_sleep + 1;
}