/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:56:09 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/21 16:13:43 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_died(t_data *data)
{
	data->died = 1;
}

void	ft_sleep(t_philo *philo)
{
	philo->sleep = 1;
	ft_print(philo);
	ft_usleep(philo, philo->ptr->time_to_sleep);
	philo->sleep = 0;
}

void	ft_eat(t_philo *philo)
{
	philo->eat = 1;
	pthread_mutex_lock(&philo->ptr->m_max_eat);
	pthread_mutex_lock(&philo->ptr->m_last_meal);
	philo->last_meal = get_current_time() - philo->ptr->start;
	philo->nb_meal++;
	pthread_mutex_unlock(&philo->ptr->m_max_eat);
	pthread_mutex_unlock(&philo->ptr->m_last_meal);
	ft_usleep(philo, philo->ptr->time_to_eat);
	philo->eat = 0;
}

void	ft_think(t_philo *philo)
{
	philo->think = 1;
	ft_print(philo);
	philo->think = 0;
}
