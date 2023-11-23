/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:07:12 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/23 21:17:04 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	free(data->fork);
	free(philo);
	pthread_mutex_destroy(&data->m_print);
	pthread_mutex_destroy(&data->m_max_eat);
	pthread_mutex_destroy(&data->m_last_meal);
	pthread_mutex_destroy(&data->m_die);
	pthread_mutex_destroy(&data->m_full);	
}