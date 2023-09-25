/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:00:08 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/25 21:25:55 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philosophers(t_data *data)
{
	set_philo(data);
}

int	main(int argc, char **argv)
{
	//init_struct fct
	t_data	data;
	t_philo	philo;
	t_error	error;

	ft_bzero(&data, sizeof(t_data));
	ft_bzero(&error, sizeof(t_error));
	ft_bzero(&philo, sizeof(t_philo));
	data.error = &error;
	data.philo = &philo;
	parsing(argc, argv, data.error);
	// printf("%i", data.nb_philo);
	if (!error.error_g)
	{
		init_argv_value(&data, argv);
		philosophers(&data);
	}
	// free_all(&data);
	return (0);
}
