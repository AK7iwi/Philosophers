/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:56:09 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/22 17:11:13 by mfeldman         ###   ########.fr       */
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
	ft_putnbr_fd(get_current_time() - philo->ptr_data->start, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(philo->id, 1);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd("is sleeping", 1);
	ft_usleep(philo, philo->ptr_data->time_to_sleep);
	
}

void	ft_eat(t_philo *philo)
{
	ft_putnbr_fd(get_current_time() - philo->ptr_data->start, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(philo->id, 1);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd("has taken a fork", 1);
	pthread_mutex_lock(&philo->ptr_data->m_max_eat);
	pthread_mutex_lock(&philo->ptr_data->m_last_meal);
	philo->last_meal = get_current_time() - philo->ptr_data->start;
	philo->nb_meal++;
	pthread_mutex_unlock(&philo->ptr_data->m_max_eat);
	pthread_mutex_unlock(&philo->ptr_data->m_last_meal);
	ft_usleep(philo, philo->ptr_data->time_to_eat);
	ft_putnbr_fd(get_current_time() - philo->ptr_data->start, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(philo->id, 1);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd("is eating", 1);
	
}

void	ft_think(t_philo *philo)
{
	// pthread_mutex_lock(&philo->ptr_data->m_die);
	ft_putnbr_fd(get_current_time() - philo->ptr_data->start, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(philo->id, 1);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd("is thinking", 1);
	// pthread_mutex_unlock(&philo->ptr_data->m_die);
}
