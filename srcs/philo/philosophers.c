/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:00:08 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/24 18:02:25 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	thread_creation()
{
	
}

void	set_philo(t_data *data)
{
	uint8_t	j;

	t_philo	philo[data->nb_philo];
	
	ft_bzero(&philo, sizeof(t_philo));
	data->philo = philo;
	j = 0;
	//nb_philo--
	while(j <= data->nb_philo)
	{
		data->philo[j]->id = j + 1;
		j++;
		printf("%i%s", data->philo[j].id, "\n");
	}
}

void	philosophers(t_data *data)
{
	set_philo(data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	// t_philo	philo;
	t_error	error;

	ft_bzero(&data, sizeof(t_data));
	ft_bzero(&error, sizeof(t_error));
	data.error = &error;
	parsing(argc, argv, data.error);
	data.nb_philo = ft_atoi(argv[1]);
	// printf("%i", data.nb_philo);
	if (!error.error_g)
		philosophers(&data);
	return (0);
}
