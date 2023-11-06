/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:11:22 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/06 23:23:32 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_test(void *arg)
{
	t_data	*data;
	int i = 0;
	data = (t_data*)arg;
	while(i < data->nb_philo)
	{	
		pthread_mutex_lock(&data->fork[i]);
		data->test++;
		pthread_mutex_unlock(&data->fork[i]);
		// usleep(1000);
		i++;
	}
	return (NULL);
}

void	init_thread(t_data *data)
{
	uint8_t	i;
	i = 0;

	while(i < data->nb_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL, &ft_test, data) != 0)
			return ;
		i++;
	}
}

void	init_mutex(t_data *data)
{
	uint8_t	i;

	i = 0;
	data->fork = malloc(sizeof(t_philo) * data->nb_philo);
	//gestion NULL + free
	if (!data->fork)
		return ;
	while(i < data->nb_philo)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
}

void	init_philo(t_data *data)
{
	uint8_t	i;
	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	//gestion NULL + free
	if (!data->philo)
		return ;
	init_mutex(data);
	while (i < data->nb_philo)
	{
		data->philo[i].id = i + 1;
		// data->philo[i].l_fork = data->philo[i].fork;
		i++;
	}
	ft_putnbr_fd(data->test, 1);
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