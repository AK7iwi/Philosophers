/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:56:09 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/23 01:42:29 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_die_or_stop(t_data *data, t_philo *philo)
{
	int	i;
	unsigned long	last_meal_cpy;
	
	while (1)
	{
		i = 0;
		while (i < data->nb_philo)
		{
			pthread_mutex_lock(&data->m_last_meal);
			last_meal_cpy = philo[i].last_meal;
			pthread_mutex_unlock(&data->m_last_meal);
			if ((get_current_time() - data->start - last_meal_cpy) >= data->time_to_die)
			{
				pthread_mutex_lock(&data->m_die);
				data->died = 1;
				pthread_mutex_unlock(&data->m_die);
				print(philo, DEAD);
				return ;
			}
			if (is_max_eat(philo))
				return ;
			i++;
		}	
	}
}

void	ft_sleep(t_philo *philo)
{
	print(philo, SLEEP);
	ft_usleep(philo, philo->ptr_data->time_to_sleep);
}

bool	eat(t_philo *philo)
{
	uint8_t l_fork;
	uint8_t r_fork;

	l_fork = philo->id - 1;
	r_fork = l_fork + 1;
	if(philo->id == philo->ptr_data->nb_philo)
		r_fork = 0;
	pthread_mutex_lock (&philo->ptr_data->fork[l_fork]);
	print(philo, FORK);
	if(philo->ptr_data->nb_philo == 1)
		return (pthread_mutex_unlock (&philo->ptr_data->fork[l_fork]), 1);
	pthread_mutex_lock (&philo->ptr_data->fork[r_fork]);
	print(philo, FORK);
	print(philo, EAT);
	pthread_mutex_lock(&philo->ptr_data->m_max_eat);
	pthread_mutex_lock(&philo->ptr_data->m_last_meal);
	philo->last_meal = get_current_time() - philo->ptr_data->start;
	philo->nb_meal++;
	pthread_mutex_unlock(&philo->ptr_data->m_max_eat);
	pthread_mutex_unlock(&philo->ptr_data->m_last_meal);
	pthread_mutex_unlock(&philo->ptr_data->fork[l_fork]);
	pthread_mutex_unlock(&philo->ptr_data->fork[r_fork]);
	ft_usleep(philo, philo->ptr_data->time_to_eat);
	return(0);
}

void think(t_philo *philo, unsigned long time)
{
	print(philo, THINK);
	ft_usleep(philo, time);
}