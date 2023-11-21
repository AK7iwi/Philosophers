/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:56:09 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/21 22:24:02 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_died(t_data *data)
{
	(void)data;
	// data->died = 1;
}

void	ft_sleep(t_philo *philo)
{
	philo->ptr_status->eat = 1;
	// ft_usleep(philo, philo->ptr->time_to_sleep);
	// ft_putnbr_fd(get_current_time() - philo->ptr_data->start, 1);
	// ft_putchar_fd(' ', 1);
	// ft_putnbr_fd(philo->id, 1);
	// ft_putchar_fd(' ', 1);
	// ft_putstr_fd("is sleeping", 1);
	// philo->sleep = 0;
}

void	ft_eat(t_philo *philo)
{
	// philo->eat = 1;
	pthread_mutex_lock(&philo->ptr_data->m_max_eat);
	pthread_mutex_lock(&philo->ptr_data->m_last_meal);
	philo->last_meal = get_current_time() - philo->ptr_data->start;
	philo->nb_meal++;
	pthread_mutex_unlock(&philo->ptr_data->m_max_eat);
	pthread_mutex_unlock(&philo->ptr_data->m_last_meal);
	ft_usleep(philo, philo->ptr_data->time_to_eat);
	// philo->eat = 0;
}

void	ft_think(t_philo *philo)
{
	// pthread_mutex_lock(&philo->ptr_data->m_die);
	philo->ptr_status->think = 1;
	// pthread_mutex_unlock(&philo->ptr_data->m_die);
}
