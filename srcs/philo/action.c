/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:56:09 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/29 01:35:42 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	max_eat(t_philo *philo)
{
	uint8_t	i;
	uint8_t	have_eat;

	i = -1;
	have_eat = 0;
	while (++i < philo->ptr_data->nb_philo)
	{
		pthread_mutex_lock(&philo->ptr_data->m_max_eat);
		if (philo[i].nb_meal == philo->ptr_data->max_eat)
		{
			pthread_mutex_unlock(&philo->ptr_data->m_max_eat);
			have_eat++;
			if (have_eat == philo->ptr_data->nb_philo)
			{
				pthread_mutex_lock(&philo->ptr_data->m_full);
				philo->ptr_data->full = 1;
				pthread_mutex_unlock(&philo->ptr_data->m_full);
				return (1);
			}
		}
		else
			pthread_mutex_unlock(&philo->ptr_data->m_max_eat);
	}
	return (0);
}

bool	ft_death(t_data *data, t_philo *philo, uint8_t i)
{
	unsigned long	last_meal_cpy;

	pthread_mutex_lock(&data->m_last_meal);
	last_meal_cpy = philo[i].last_meal;
	pthread_mutex_unlock(&data->m_last_meal);
	if ((get_current_time() - data->start - last_meal_cpy) >= data->time_to_die)
	{
		pthread_mutex_lock(&data->m_die);
		data->died = 1;
		pthread_mutex_unlock(&data->m_die);
		print(philo, DEAD);
		return (1);
	}
	return (0);
}

void	ft_sleep(t_philo *philo)
{
	print(philo, SLEEP);
	ft_usleep(philo, philo->ptr_data->time_to_sleep);
}

bool	eat(t_philo *philo)
{
	uint8_t	l_fork;
	uint8_t	r_fork;

	l_fork = philo->id - 1;
	r_fork = l_fork + 1;
	if (philo->id == philo->ptr_data->nb_philo)
		r_fork = 0;
	pthread_mutex_lock (&philo->ptr_data->fork[l_fork]);
	print(philo, FORK);
	if (philo->ptr_data->nb_philo == 1)
		return (pthread_mutex_unlock (&philo->ptr_data->fork[l_fork]), 1);
	pthread_mutex_lock (&philo->ptr_data->fork[r_fork]);
	print(philo, FORK);
	print(philo, EAT);
	pthread_mutex_lock(&philo->ptr_data->m_last_meal);
	philo->last_meal = get_current_time() - philo->ptr_data->start;
	pthread_mutex_unlock(&philo->ptr_data->m_last_meal);
	pthread_mutex_lock(&philo->ptr_data->m_max_eat);
	philo->nb_meal++;
	pthread_mutex_unlock(&philo->ptr_data->m_max_eat);
	pthread_mutex_unlock(&philo->ptr_data->fork[l_fork]);
	pthread_mutex_unlock(&philo->ptr_data->fork[r_fork]);
	ft_usleep(philo, philo->ptr_data->time_to_eat);
	return (0);
}

void	think(t_philo *philo, unsigned long time)
{
	print(philo, THINK);
	ft_usleep(philo, time);
}
