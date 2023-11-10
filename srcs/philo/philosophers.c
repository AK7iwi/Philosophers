/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:00:08 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/10 14:11:26 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *arg)
{
	t_data	*data;
	data = (t_data*)arg;
	pthread_mutex_lock(&data->fork[data->philo->id - 1]);
	
	// if(!is_dead(data))
	// {
	// 	if(data->philo->id % 2 == 0)
	// 		ft_sleep(data);
	// 	else
	// 		ft_eat(data);
	// }
	
	printf("%d", data->philo->last_meal);
	pthread_mutex_unlock(&data->fork[data->philo->id - 1]);
	// is_dead(data);
	// ft_print(data);
	return (NULL);
}

void	philosophers(t_data *data, char **argv)
{
	init_struct_and_argv_value(data, argv);
	if(init_mutex(data) || init_philo(data) || init_thread(data))
		return ;
		
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_error	error;
	
	ft_bzero(&data, sizeof(t_data));
	ft_bzero(&error, sizeof(t_error));
	data.error = &error;
	parsing(argc, argv, data.error);
	if (!data.error->error_g)
		philosophers(&data, argv);
	ft_destroy(&data);
	free(data.philo);
	return (0);
}
