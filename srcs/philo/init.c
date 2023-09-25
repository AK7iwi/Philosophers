/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:11:22 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/25 21:25:24 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void*	ft_test(void *arg)
{
	t_data* data = (t_data*)arg;
	data->philo[1].test++;
	ft_putnbr_fd(data->philo[1].test++,1);	
	return (NULL);
}

void	set_philo(t_data *data)
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
		pthread_create(&data->philo[i].thread, NULL, ft_test, data);
		i++;
	}
	// free(data->philo);
}

void	init_argv_value(t_data *data, char **argv)
{
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
}