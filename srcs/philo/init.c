/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:11:22 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/26 22:20:21 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_test(void *arg)
{
	t_data	*data;
	
	data = (t_data*)arg;

	// pthread_mutex_lock(&data.philo[i].id->fork);
	// // data->philo[1].test++;
	// // ft_putnbr_fd(data->philo.test++, 1);
	// pthread_mutex_unlock(&data.philo.id->fork);
	data->philo.test++;
	return (NULL);
}

// void	init_mutex(t_data *data)
// {
// 	uint8_t	i;
// 	pthread_mutex_t	*mutex;

// 	i = 0;
// 	mutex = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
// 	if (!mutex)
// 		return ;
// 	while(i < data->nb_philo)
// 		pthread_mutex_init(&data->philo.fork[i++], NULL);
// 	// data.philo->fork = mutex;
// }

void	init_philo(t_data *data)
{
	uint8_t	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	//gestion NULL
	if (!data->philo)
		return ;	
	while (i < data->nb_philo)
	{
		data->philo[i].id = i + 1;
		if (pthread_create(&data->philo[i].thread, NULL, &ft_test, data) != 0)
			return ;
		i++;
	}
}

void	init_struct_and_argv_value(t_data *data, char **argv)
{
	t_philo	*philo;
	t_error	error;

	ft_bzero(data, sizeof(t_data));
	ft_bzero(&error, sizeof(t_error));
	ft_bzero(philo, sizeof(t_philo)); //verif l'utilité de ca
	data->error = &error;
	data->philo = philo;
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	// data->max_eat= ft_atoi(argv[5]);
}