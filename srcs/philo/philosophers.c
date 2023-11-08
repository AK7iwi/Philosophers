/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:00:08 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/08 23:49:27 by mfeldman         ###   ########.fr       */
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

void	philosophers(t_data *data, char **argv)
{
	init_struct_and_argv_value(data, argv);
	//test du return
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
