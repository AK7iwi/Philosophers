/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:39:00 by mfeldman          #+#    #+#             */
/*   Updated: 2023/11/14 20:22:20 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(t_philo *philo)
{
	long long	start_time;
	// a modif 
	start_time = get_current_time();
	while (((get_current_time() - start_time) * 1000) < philo->ptr->time_to_sleep && !is_dead(philo) && !is_max_eat(philo))
		usleep(50);
}

int is_max_eat(t_philo *philo)
{
	if(philo->nb_meal == philo->ptr->max_eat)
		return (1);
	return (0);
}

long	get_current_time(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000;
	time += tv.tv_usec / 1000;
	return (time);
}

int	is_dead(t_philo *philo)
{
	long time;

	time = get_current_time() - philo->ptr->start;
	if(time - philo->last_meal > philo->ptr->time_to_die)
	{
		philo->dead = 1;
		return(1);
	}
	return(0);
}
