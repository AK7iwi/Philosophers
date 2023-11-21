/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:39:00 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/21 21:47:57 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(t_philo *philo, unsigned long time)
{
	unsigned long	start_time;

	start_time = get_current_time();
	while (((get_current_time() - start_time) * 1000) < 
	time && 
	!is_dead(philo) && !is_max_eat(philo))
		usleep(50);
}

int is_max_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->ptr_data->m_max_eat);
	if(philo->nb_meal == philo->ptr_data->max_eat)
		return (1);
	pthread_mutex_unlock(&philo->ptr_data->m_max_eat);
	return (0);
}


int	is_dead(t_philo *philo)
{
	long time;

	time = get_current_time() - philo->ptr_data->start;
	if(time - philo->last_meal > philo->ptr_data->time_to_die)
	{
		// philo->dead = 1;
		return(1);
	}
	return(0);
}

unsigned long	get_current_time(void)
{
	struct timeval	tv;
	long			time;

	if(gettimeofday(&tv, NULL) == -1)
		ft_putstr_fd("Time error", 1);
	time = tv.tv_sec * 1000;
	time += tv.tv_usec / 1000;
	return (time);
}
